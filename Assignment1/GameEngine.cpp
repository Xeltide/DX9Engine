#include "GameEngine.h"

using namespace std;
GameEngine::GameEngine()
{
	mRenderEngine = make_shared<RenderEngine>();
	mStateManager = new GameStateManager();
}

GameEngine::~GameEngine()
{
}

BOOL GameEngine::Init(HWND hWnd)
{
	BOOL noError = mRenderEngine->Init(hWnd);
	// TODO: Scenes needs to be initialized after render engine initialization
	if (noError)
	{
		TestScene* startScene = new TestScene(mRenderEngine->GetDevice());
		mRenderEngine->LoadScene(startScene);
		mStateManager->PushState(new GameState(startScene));
		//mStateManager = new GameStateManager(new GameState(startScene));
	}
	return noError;
}

BOOL GameEngine::Loop(double deltaTime)
{
	mStateManager->Update(deltaTime);
	mRenderEngine->RenderScene(deltaTime, mStateManager->GetState()->GetCurrentScene());

	if (GetAsyncKeyState(VK_ESCAPE))
		PostQuitMessage(0);

	return TRUE;
}

shared_ptr<InputController> GameEngine::GetInputController()
{
	return mStateManager->GetInputController();
}