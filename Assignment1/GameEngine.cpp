#include "GameEngine.h"

using namespace std;
GameEngine::GameEngine()
{
	mRenderEngine = make_shared<RenderEngine>();
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
		mStateManager = new GameStateManager(new GameState(new TestScene(mRenderEngine->GetDevice())));
	}
	return noError;
}

BOOL GameEngine::Loop(double deltaTime)
{
	mRenderEngine->RenderScene(deltaTime, mStateManager->GetState()->GetCurrentScene());

	if (GetAsyncKeyState(VK_ESCAPE))
		PostQuitMessage(0);

	return TRUE;
}