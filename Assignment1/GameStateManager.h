#pragma once
#include <stack>
#include "GameState.h"
#include "InputController.h"

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
	GameStateManager();
	GameStateManager(GameState*);

	void Switch(GameState*);
	GameState* GetState();
	void PushState(GameState* state);

	void Update(double deltaTime);

	shared_ptr<InputController> GetInputController();
private:
	GameState* mCurrentState;
	stack<GameState*> mStateStack;
	shared_ptr<InputController> mInputController;
};