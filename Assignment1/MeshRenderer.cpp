#include "MeshRenderer.h"

MeshRenderer::MeshRenderer(std::string filePath)
	: mFilePath(filePath)
{
}

MeshRenderer::~MeshRenderer()
{
	Release();
}

HRESULT MeshRenderer::Load(LPDIRECT3DDEVICE9 dxDevice)
{
	LPD3DXBUFFER pD3DXMtrlBuffer;

	// Load the mesh from the specified file
	if (FAILED(D3DXLoadMeshFromX(mFilePath.c_str(), D3DXMESH_SYSTEMMEM,
		dxDevice, NULL,
		&pD3DXMtrlBuffer, NULL, &m_dwNumMaterials,
		&m_pMesh)))
	{
		std::string errorMsg = "Could not find " + mFilePath;
		MessageBox(NULL, errorMsg.c_str(), "DXScene.exe", MB_OK);
		return E_FAIL;
	}

	// We need to extract the material properties and texture names from the 
	// pD3DXMtrlBuffer
	D3DXMATERIAL* d3dxMaterials = (D3DXMATERIAL*)pD3DXMtrlBuffer->GetBufferPointer();
	m_pMeshMaterials = new D3DMATERIAL9[m_dwNumMaterials];
	m_pMeshTextures = new LPDIRECT3DTEXTURE9[m_dwNumMaterials];

	for (DWORD i = 0; i < m_dwNumMaterials; i++)
	{
		// Copy the material
		m_pMeshMaterials[i] = d3dxMaterials[i].MatD3D;

		// Set the ambient color for the material (D3DX does not do this)
		m_pMeshMaterials[i].Ambient = m_pMeshMaterials[i].Diffuse;

		m_pMeshTextures[i] = NULL;
		if (d3dxMaterials[i].pTextureFilename != NULL &&
			lstrlen(d3dxMaterials[i].pTextureFilename) > 0)
		{
			// Create the texture
			if (FAILED(D3DXCreateTextureFromFile(dxDevice,
				d3dxMaterials[i].pTextureFilename,
				&m_pMeshTextures[i])))
			{
				MessageBox(NULL, "Could not find texture map", "DXScene.exe", MB_OK);
			}
		}
	}

	// Done with the material buffer
	pD3DXMtrlBuffer->Release();

	return S_OK;
}

const DWORD MeshRenderer::GetNumMaterials()
{
	return m_dwNumMaterials;
}

const D3DMATERIAL9* MeshRenderer::GetMeshMaterials()
{
	return m_pMeshMaterials;
}

const LPDIRECT3DTEXTURE9* MeshRenderer::GetMeshTextures()
{
	return m_pMeshTextures;
}

const LPD3DXMESH MeshRenderer::GetMesh()
{
	return m_pMesh;
}

void MeshRenderer::Release()
{
	if (m_pMeshMaterials != NULL)
		delete[] m_pMeshMaterials;

	if (m_pMeshTextures)
	{
		for (DWORD i = 0; i < m_dwNumMaterials; i++)
		{
			if (m_pMeshTextures[i])
				m_pMeshTextures[i]->Release();
		}
		delete[] m_pMeshTextures;
	}
	if (m_pMesh != NULL)
		m_pMesh->Release();
}