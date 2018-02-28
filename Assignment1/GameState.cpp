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

vector<Scene*> GameState::GetScenes()
{
	return mScenes;
}

void GameState::Update(double deltaTime)
{
	mScenes[mSceneIndex]->Update(deltaTime);
}