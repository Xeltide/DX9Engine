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

/*void Scene::PushText(TextRenderer* text)
{
	mAllTextRenderer.push_back(text);
}

const TextRenderer* Scene::GetText(const unsigned int index)
{
	return mAllTextRenderer[index];
}

const vector<TextRenderer*> Scene::GetAllText()
{
	return mAllTextRenderer;
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
}*/

void Scene::PushObject(GameObject* object)
{
	mObjects.push_back(object);
}

const GameObject* Scene::GetGameObject(const unsigned int index)
{
	return mObjects[index];
}

const vector<GameObject*> Scene::GetGameObjects()
{
	return mObjects;
}

void Scene::Update(double deltaTime)
{
	for (auto it = mObjects.begin(); it != mObjects.end(); it++)
	{
		(*it)->Update(deltaTime);
	}
}
