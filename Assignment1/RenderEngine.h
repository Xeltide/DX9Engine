#pragma once
#include <Windows.h>
#include <d3d9.h>
#include <d3dx9.h>
#include "Scene.h"
#include "GameWindow.h"

/*
RenderEngine Class:
- Wrapper for DirectX draw calls, managed by the GameEngine
- Renders Scene data
*/
class RenderEngine
{
public:
	
	RenderEngine();
	/*
	Use:
	- Releases the LPDIRECT3D9 and LPDIRECT3DDEVICE9
	*/
	virtual ~RenderEngine();

	/*
	Use:
	- Second step initialization to ensure
	that critical structure setup has been successful
	- Must be called manually

	Parameters:
	@HWND - handle to the window

	Returns:
	@boolean - true if successful init
	*/
	BOOL Init(HWND);
	/*
	Use:
	- Intiailizes the direct3D device
	*/
	BOOL InitDirect3DDevice(HWND, int, int, BOOL, D3DFORMAT, LPDIRECT3D9, LPDIRECT3DDEVICE9*);
	/*
	Use:
	- Draws the current Scene data
	- Currently takes the delta time for FPS counting

	Parameters:
	@double - time in seconds
	@Scene* - the scene to render

	Returns:
	@BOOL - true if successful
	*/
	BOOL RenderScene(double, Scene*);
	void LoadScene(Scene* scene);
	// ARTIFACT - potential reuse later
	void Draw(int, DWORD*);

	/*
	Returns:
	@LPDIRECT3DDEVICE9 - the current device
	*/
	LPDIRECT3DDEVICE9 GetDevice();
	/*
	Use:
	- Draws the text inside the Scene* data
	*/
	void RenderText(Scene*);
	void RenderMeshes(Scene*);
private:
	HRESULT RenderObjects(Scene*);

	LPDIRECT3D9 m_pD3D;
	LPDIRECT3DDEVICE9 m_pDevice;
	int mAmbientLighting = 0xFFFFFF;
};