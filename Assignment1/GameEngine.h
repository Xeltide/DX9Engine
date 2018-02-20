#pragma once
#include <Windows.h>
#include <memory>

#include "RenderEngine.h"
#include "GameStateManager.h"
#include "TestScene.h"

/*
GameEngine Class:
- Manages the various engines running the game
- Currently only has the rendering engine
  and state manager
*/
class GameEngine
{
public:
	/*
	Use:
	- Initializes the internal engines
	*/
	GameEngine();
	/*
	Use:
	- Destroys the internal engines and shutsdown
	*/
	virtual ~GameEngine();

	/*
	Use:
	- Second step initialization to ensure
	  that critical structure setup has been successful
	- Must be called manually

	Returns:
	@boolean - true if successful init
	*/
	BOOL Init(HWND);
	/*
	Use:
	- Repeatedly called to continue execution of
	  various engines and currently loaded states

	Returns:
	@boolean - true if successful loop
	*/
	BOOL Loop(double);

private:
	shared_ptr<RenderEngine> mRenderEngine;
	GameStateManager* mStateManager;
};