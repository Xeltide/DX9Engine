#include "GameStateManager.h"

GameStateManager::GameStateManager()
{
	mInputController = make_shared<InputController>();
}

GameStateManager::GameStateManager(GameState* initialState)
	: mCurrentState(initialState)
{
	for (auto it = initialState->GetScenes().begin(); it != initialState->GetScenes().end(); it++)
	{
		for (auto itObj = (*it)->GetGameObjects().begin(); itObj != (*it)->GetGameObjects().end(); itObj++)
		{
			(*itObj)->SetInputController(mInputController);
		}
	}
	mStateStack.push(initialState);
	mInputController = make_shared<InputController>();
}

GameState* GameStateManager::GetState()
{
	return mCurrentState;
}

void GameStateManager::PushState(GameState* state)
{
	vector<Scene*> scenes = state->GetScenes();
	for (auto it = scenes.begin(); it != scenes.end(); it++)
	{
		vector<GameObject*> objects = (*it)->GetGameObjects();
		for (auto itObj = objects.begin(); itObj != objects.end(); itObj++)
		{
			(*itObj)->SetInputController(mInputController);
		}
	}
	mCurrentState = state;
	mStateStack.push(state);
}

void GameStateManager::Update(double deltaTime)
{
	mCurrentState->Update(deltaTime);
}

shared_ptr<InputController> GameStateManager::GetInputController()
{
	return mInputController;
}