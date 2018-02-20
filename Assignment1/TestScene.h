#pragma once
#include <d3dx9.h>
#include "Scene.h"
/*
TestScene Class:
- current demo scene
- custom implementations of scenes will be used to organize data
*/
class TestScene : public Scene
{
public:
	/*
	Use:
	- Creates and loads the test scene and it's render data

	Parameters:
	@LPDIRECT3DDEVICE - the current directX device
	*/
	TestScene(LPDIRECT3DDEVICE9);
	/*
	Use:
	- Creates and loads the test scene and it's render data

	Parameters:
	@LPDIRECT3DDEVICE - the current directX device
	@LPDIRECT3DSURFACE9 - default background image to load
	*/
	TestScene(LPDIRECT3DDEVICE9, LPDIRECT3DSURFACE9);
	virtual ~TestScene() = default;
};