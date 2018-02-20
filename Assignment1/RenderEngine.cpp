#include "RenderEngine.h"

RenderEngine::RenderEngine()
	: m_pD3D(NULL)
	, m_pDevice(NULL) {}

RenderEngine::~RenderEngine()
{
	if (m_pDevice)
	{
		m_pDevice->Release();
	}

	if (m_pD3D)
	{
		m_pD3D->Release();
	}
}

BOOL RenderEngine::Init(HWND hWnd)
{
	HRESULT r = 0;

	m_pD3D = Direct3DCreate9(D3D_SDK_VERSION);
	if (m_pD3D == NULL)
	{
		// TODO: Error message and close
		return FALSE;
	}

	r = InitDirect3DDevice(hWnd, GameWindow::WIDTH, GameWindow::HEIGHT, FALSE, D3DFMT_X8R8G8B8, m_pD3D, &m_pDevice);
	if (FAILED(r))
	{
		// TODO: Error message and close
		return FALSE;
	}

	return TRUE;
}

BOOL RenderEngine::InitDirect3DDevice(HWND hWndTarget, int Width, int Height, BOOL bWindowed, D3DFORMAT FullScreenFormat, LPDIRECT3D9 pD3D, LPDIRECT3DDEVICE9* ppDevice)
{
	D3DPRESENT_PARAMETERS d3dpp;
	D3DDISPLAYMODE d3ddm;
	HRESULT r = 0;

	if (*ppDevice)
	{
		(*ppDevice)->Release();
	}

	ZeroMemory(&d3dpp, sizeof(D3DPRESENT_PARAMETERS));
	r = pD3D->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &d3ddm);
	if (FAILED(r))
	{
		// TODO: Error message and close
		return FALSE;
	}

	d3dpp.BackBufferWidth = Width;
	d3dpp.BackBufferHeight = Height;
	d3dpp.BackBufferFormat = bWindowed ? d3ddm.Format : FullScreenFormat;
	d3dpp.BackBufferCount = 1;
	d3dpp.MultiSampleType = D3DMULTISAMPLE_NONE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.hDeviceWindow = hWndTarget;
	d3dpp.Windowed = bWindowed;
	d3dpp.EnableAutoDepthStencil = TRUE;
	d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
	d3dpp.FullScreen_RefreshRateInHz = 0;
	d3dpp.PresentationInterval = bWindowed ? 0 : D3DPRESENT_INTERVAL_IMMEDIATE;
	d3dpp.Flags = D3DPRESENTFLAG_LOCKABLE_BACKBUFFER;

	r = pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWndTarget, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, ppDevice);
	if (FAILED(r))
	{
		// TODO: Error message and close
		return FALSE;
	}
	return TRUE;
}

BOOL RenderEngine::RenderScene(double deltaTime, Scene* scene)
{
	HRESULT r;
	D3DLOCKED_RECT LockedRect;//locked area of display memory(buffer really) we are drawing to
	LPDIRECT3DSURFACE9 pBackSurf = 0;

	mFrameCount++;
	mTimeSum += deltaTime;

	if (mTimeSum >= 1)
	{
		mFPS = mFrameCount;
		mTimeSum -= 1;
		mFrameCount = 0;
	}

	if (!m_pDevice)
	{
		//SetError("Cannot render because there is no device");
		return E_FAIL;
	}

	//clear the display arera with colour black, ignore stencil buffer
	m_pDevice->Clear(0, 0, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 25), 1.0f, 0);

	//get pointer to backbuffer
	r = m_pDevice->GetBackBuffer(0, 0, D3DBACKBUFFER_TYPE_MONO, &pBackSurf);
	if (FAILED(r))
	{
		//SetError("Couldn't get backbuffer");
	}

	// Draw scene background if available
	if (scene->GetBGSurface() != nullptr)
	{
		if (FAILED(m_pDevice->UpdateSurface(scene->GetBGSurface(), NULL, pBackSurf, NULL)))
		{
			OutputDebugString("UpdateSurface failed\n");
		}
	}

	//get a lock on the surface
	r = pBackSurf->LockRect(&LockedRect, NULL, 0);
	if (FAILED(r))
	{
		//SetError("Could not lock the back buffer");
	}

	RenderObjects(scene);

	DWORD* pData = (DWORD*)(LockedRect.pBits);
	//DRAW CODE GOES HERE - use pData
	Draw(LockedRect.Pitch, pData);

	pBackSurf->UnlockRect();
	pData = 0;

	pBackSurf->Release();//release lock
	pBackSurf = 0;
	
	m_pDevice->Present(NULL, NULL, NULL, NULL);//swap over buffer to primary surface
	return TRUE;
}

HRESULT RenderEngine::RenderObjects(Scene* scene)
{
	m_pDevice->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_SELECTARG1);
	m_pDevice->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	m_pDevice->SetTextureStageState(0, D3DTSS_COLORARG2, D3DTA_DIFFUSE);
	if (SUCCEEDED(m_pDevice->BeginScene()))
	{
		// BEGIN CAMERA
		// For our world matrix, we will just leave it as the identity
		//D3DXMATRIXA16 matWorld;
		//D3DXMatrixRotationY(&matWorld, timeGetTime() / 1000.0f);
		//m_pDevice->SetTransform(D3DTS_WORLD, &matWorld);

		// Set up our view matrix. A view matrix can be defined given an eye point,
		// a point to lookat, and a direction for which way is up. Here, we set the
		// eye five units back along the z-axis and up three units, look at the 
		// origin, and define "up" to be in the y-direction.
		D3DXVECTOR3 vEyePt(0.0f, 3.0f, -10.0f);
		D3DXVECTOR3 vLookatPt(0.0f, 0.0f, 0.0f);
		D3DXVECTOR3 vUpVec(0.0f, 1.0f, 0.0f);
		D3DXMATRIXA16 matView;
		D3DXMatrixLookAtLH(&matView, &vEyePt, &vLookatPt, &vUpVec);
		m_pDevice->SetTransform(D3DTS_VIEW, &matView);

		// For the projection matrix, we set up a perspective transform (which
		// transforms geometry from 3D view space to 2D viewport space, with
		// a perspective divide making objects smaller in the distance). To build
		// a perpsective transform, we need the field of view (1/4 pi is common),
		// the aspect ratio, and the near and far clipping planes (which define at
		// what distances geometry should be no longer be rendered).
		D3DXMATRIXA16 matProj;
		D3DXMatrixPerspectiveFovLH(&matProj, D3DX_PI / 4, 1.0f, 1.0f, 100.0f);
		m_pDevice->SetTransform(D3DTS_PROJECTION, &matProj);
		// END CAMERA

		RenderMeshes(scene);
		RenderText(scene);
		m_pDevice->EndScene();
		return S_OK;
	}
}

void RenderEngine::Draw(int Pitch, DWORD* pData)
{
	//DWORD Offset = 100 * Pitch / 4 + 200;
	//pData[Offset] = D3DCOLOR_XRGB(255, 0, 0);

	//SimpleBitmapDraw();
}

void RenderEngine::RenderMeshes(Scene* scene)
{
	vector<MeshRenderer*> allMeshes = scene->GetAllMeshes();
	for (auto it = allMeshes.begin(); it != allMeshes.end(); ++it)
	{
		// Meshes are divided into subsets, one for each material. Render them in
		// a loop
		DWORD numMaterials = (*it)->GetNumMaterials();
		for (DWORD i = 0; i < numMaterials; i++)
		{
			// Set the material and texture for this subset
			m_pDevice->SetMaterial(&((*it)->GetMeshMaterials()[i]));
			m_pDevice->SetTexture(0, (*it)->GetMeshTextures()[i]);

			// Draw the mesh subset
			if (FAILED((*it)->GetMesh()->DrawSubset(i)))
			{
				OutputDebugString("FAILED TO DRAW MESH\n");
			}
		}
	}
}

void RenderEngine::RenderText(Scene* scene)
{
	vector<DXText*> allText = scene->GetAllText();
	(*allText.begin())->SetText(to_string(mFPS));
	for (auto it = allText.begin(); it != allText.end(); ++it)
	{
		(*it)->Draw();
	}
}

LPDIRECT3DDEVICE9 RenderEngine::GetDevice()
{
	return m_pDevice;
}