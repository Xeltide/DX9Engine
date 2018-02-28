#pragma once
#include <map>
#include <mutex>

#include "KeyState.h"

class InputController
{
	friend class GameWindow;
public:
	InputController();
	virtual ~InputController() = default;

	bool IsPressed(std::string key);
	bool IsDown(std::string key);
	bool Released(std::string key);
private:
	KeyState* GetKey(std::string key);
	std::map<std::string, KeyState*> GetKeys();

	std::map<std::string, KeyState*> mKeys;
	std::mutex mInputMutex;
};