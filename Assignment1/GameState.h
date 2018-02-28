#pragma once
#include "Scene.h"
#include <vector>

/*
GameState Class:
- Manages current game state and rendered
  scenes

TODO:
- Finish method implementations
- Hook into StateManager correctly
- Current game will only need one state
  considering it's one scene
*/
using namespace std;
class GameState
{
public:
	GameState() = default;
	GameState(Scene*);
	virtual ~GameState() = default;

	void AddScene(Scene*);
	Scene* GetScene(const unsigned int);
	Scene* GetCurrentScene();
	vector<Scene*> GetScenes();
	void RemoveScene(Scene*);
	void RemoveScene(const unsigned int);

	void Update(double deltaTime);
	void Render();

	void SetInputController(InputController* inputController);
private:
	int mSceneIndex = -1;
	vector<Scene*> mScenes;
};