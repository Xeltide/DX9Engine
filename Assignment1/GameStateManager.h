#pragma once
#include "GameState.h"

/*
GameStateManager Class:
- Manages the current game state and renderable scene

TODO:
- Finish implementing methods
- Implement internal state stack
- Current game will only need one state
  considering it's one scene
*/
class GameStateManager
{
public:
	GameStateManager() = default;
	GameStateManager(GameState*);

	void Switch(GameState*);
	GameState* GetState();
private:
	GameState * mCurrentState;
};