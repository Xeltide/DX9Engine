#include "GameState.h"

GameState::GameState(Scene* initialScene)
{
	mScenes.push_back(initialScene);
	mSceneIndex = 0;
}

Scene* GameState::GetCurrentScene()
{
	return mScenes[mSceneIndex];
}