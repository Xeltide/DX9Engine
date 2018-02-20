#pragma once
#include <d3dx9.h>
#include <memory>
#include <string>
#include <vector>

#include "DXText.h"
#include "MeshRenderer.h"
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

	void PushText(DXText*);
	const DXText* GetText(const unsigned int);
	const vector<DXText*> GetAllText();

	void PushMesh(MeshRenderer*);
	const MeshRenderer* GetMesh(const unsigned int);
	const vector<MeshRenderer*> GetAllMeshes();

protected:
	LPDIRECT3DDEVICE9 m_pDevice = 0;

private:
	LPDIRECT3DSURFACE9 m_pBGSurface = 0;
	vector<DXText*> mAllDXText;
	vector<MeshRenderer*> mAllMeshes;
};