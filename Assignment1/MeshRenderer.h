#pragma once
#include <string>
#include <d3dx9.h>

class MeshRenderer
{
public:
	MeshRenderer(std::string filePath);
	~MeshRenderer();

	void Release();
	HRESULT Load(LPDIRECT3DDEVICE9);

	const DWORD GetNumMaterials();
	const D3DMATERIAL9* GetMeshMaterials();
	const LPDIRECT3DTEXTURE9* GetMeshTextures();
	const LPD3DXMESH GetMesh();
private:
	std::string mFilePath;
	LPD3DXMESH m_pMesh = NULL; // Our mesh object in sysmem
	D3DMATERIAL9* m_pMeshMaterials = NULL; // Materials for our mesh
	LPDIRECT3DTEXTURE9* m_pMeshTextures = NULL; // Textures for our mesh
	DWORD m_dwNumMaterials = 0L;   // Number of mesh materials
};