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

	m_pDevice->SetRenderState(D3DRS_LIGHTING, TRUE);
	//m_pDevice->SetRenderState(D3DRS_AMBIENT, 0xFFFFFF);
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
	LPDIRECT3DSURFACE9 pBackSurf = 0;

	if (!m_pDevice)
	{
		OutputDebugString("No device found\n");
		return E_FAIL;
	}

	//clear the display arera with colour black, ignore stencil buffer
	m_pDevice->Clear(0, 0, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0, 0, 25), 1.0f, 0);

	//get pointer to backbuffer
	r = m_pDevice->GetBackBuffer(0, 0, D3DBACKBUFFER_TYPE_MONO, &pBackSurf);
	if (FAILED(r))
	{
		OutputDebugString("GetBackBuffer failed\n");
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

	RenderObjects(scene);

	pBackSurf->Release();//release lock
	pBackSurf = 0;
	
	m_pDevice->Present(NULL, NULL, NULL, NULL);//swap over buffer to primary surface
	return TRUE;
}

HRESULT RenderEngine::RenderObjects(Scene* scene)
{
	if (SUCCEEDED(m_pDevice->BeginScene()))
	{
		// BEGIN CAMERA

		// Set up our view matrix. A view matrix can be defined given an eye point,
		// a point to lookat, and a direction for which way is up. Here, we set the
		// eye five units back along the z-axis and up three units, look at the 
		// origin, and define "up" to be in the y-direction.
		const GameObject* camera = scene->GetGameObject(0);
		D3DXMATRIXA16 cameraMatrix = camera->GetTransform().GetMatrix();
		m_pDevice->SetTransform(D3DTS_VIEW, &cameraMatrix);

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
	return E_FAIL;
}

void RenderEngine::RenderMeshes(Scene* scene)
{
	vector<GameObject*> objects = scene->GetGameObjects();
	for (auto it = objects.begin(); it != objects.end(); it++)
	{
		if ((*it)->GetMeshRenderer() != nullptr)
		{
			m_pDevice->SetTransform(D3DTS_WORLD, &((*it)->GetTransform().GetMatrix()));
			// Meshes are divided into subsets, one for each material. Render them in
			// a loop
			MeshRenderer* mesh = (*it)->GetMeshRenderer();
			DWORD numMaterials = mesh->GetNumMaterials();
			for (DWORD i = 0; i < numMaterials; i++)
			{
				// Set the material and texture for this subset
				m_pDevice->SetMaterial(&(mesh->GetMeshMaterials()[i]));
				m_pDevice->SetTexture(0, mesh->GetMeshTextures()[i]);

				// Draw the mesh subset
				if (FAILED(mesh->GetMesh()->DrawSubset(i)))
				{
					OutputDebugString("FAILED TO DRAW MESH\n");
				}
			}
		}
	}
}

void RenderEngine::RenderText(Scene* scene)
{
	vector<GameObject*> objects = scene->GetGameObjects();
	for (auto it = objects.begin(); it != objects.end(); it++)
	{
		if ((*it)->GetTextRenderer() != nullptr)
		{
			(*it)->GetTextRenderer()->Draw();
		}
	}
}

LPDIRECT3DDEVICE9 RenderEngine::GetDevice()
{
	return m_pDevice;
}

void RenderEngine::LoadScene(Scene* scene)
{
	unsigned int lightNumber = 0;
	vector<GameObject*> objects = scene->GetGameObjects();
	for (auto it = objects.begin(); it != objects.end(); it++)
	{
		if ((*it)->GetMeshRenderer() != nullptr)
		{
			(*it)->GetMeshRenderer()->Load(m_pDevice);
		}
		if ((*it)->GetLightRenderer() != nullptr)
		{
			(*it)->GetLightRenderer()->Load(m_pDevice, lightNumber);
			lightNumber++;
		}
	}
}