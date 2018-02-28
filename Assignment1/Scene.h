#pragma once
#include <d3dx9.h>
#include <memory>
#include <string>
#include <vector>

#include "GameObject.h"
//#include "TextRenderer.h"
//#include "MeshRenderer.h"
/*
Scene Class:
- Contains the render data for a particular scene
- Grouping of logical render data, a subsection
  of a GameState
*/
using namespace std;
class Scene
{
public:
	Scene(LPDIRECT3DDEVICE9);
	Scene(LPDIRECT3DDEVICE9, LPDIRECT3DSURFACE9);
	virtual ~Scene() = default;

	void SetDevice(LPDIRECT3DDEVICE9);

	void SetBGSurface(LPDIRECT3DSURFACE9);
	const LPDIRECT3DSURFACE9 GetBGSurface();

	/*void PushText(TextRenderer*);
	const TextRenderer* GetText(const unsigned int);
	const vector<TextRenderer*> GetAllText();

	void PushMesh(MeshRenderer*);
	const MeshRenderer* GetMesh(const unsigned int);
	const vector<MeshRenderer*> GetAllMeshes();*/

	void PushObject(GameObject* object);
	const GameObject* GetGameObject(const unsigned int);
	const vector<GameObject*> GetGameObjects();

	void Update(double deltaTime);
protected:
	LPDIRECT3DDEVICE9 m_pDevice = 0;

private:
	bool mLoaded;
	LPDIRECT3DSURFACE9 m_pBGSurface = 0;
	vector<GameObject*> mObjects;
	/*vector<TextRenderer*> mAllTextRenderer;
	vector<MeshRenderer*> mAllMeshes;*/
};