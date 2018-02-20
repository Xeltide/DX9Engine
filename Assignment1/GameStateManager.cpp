#include "GameStateManager.h"

GameStateManager::GameStateManager(GameState* initialState)
	: mCurrentState(initialState)
{
}

GameState* GameStateManager::GetState()
{
	return mCurrentState;
}