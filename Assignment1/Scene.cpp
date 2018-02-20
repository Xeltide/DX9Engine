#include "Scene.h"

Scene::Scene(LPDIRECT3DDEVICE9 device)
	: m_pDevice(device)
{
}

Scene::Scene(LPDIRECT3DDEVICE9 device, LPDIRECT3DSURFACE9 bgSurface)
	: m_pDevice(device)
	, m_pBGSurface(bgSurface)
{
}

void Scene::SetDevice(LPDIRECT3DDEVICE9 device)
{
	m_pDevice = device;
}

void Scene::SetBGSurface(LPDIRECT3DSURFACE9 surface)
{
	m_pBGSurface = surface;
}

const LPDIRECT3DSURFACE9 Scene::GetBGSurface()
{
	return m_pBGSurface;
}

void Scene::PushText(DXText* text)
{
	mAllDXText.push_back(text);
}

const DXText* Scene::GetText(const unsigned int index)
{
	return mAllDXText[index];
}

const vector<DXText*> Scene::GetAllText()
{
	return mAllDXText;
}

void Scene::PushMesh(MeshRenderer* mesh)
{
	mAllMeshes.push_back(mesh);
}

const MeshRenderer* Scene::GetMesh(const unsigned int index)
{
	return mAllMeshes[index];
}

const vector<MeshRenderer*> Scene::GetAllMeshes()
{
	return mAllMeshes;
}