#include "InputController.h"

InputController::InputController()
{
	mKeys.insert(std::make_pair<std::string, KeyState*>("1", new KeyState()));
	mKeys.insert(std::make_pair<std::string, KeyState*>("2", new KeyState()));
	mKeys.insert(std::make_pair<std::string, KeyState*>("3", new KeyState()));
	mKeys.insert(std::make_pair<std::string, KeyState*>("A", new KeyState()));
	mKeys.insert(std::make_pair<std::string, KeyState*>("D", new KeyState()));
	mKeys.insert(std::make_pair<std::string, KeyState*>("E", new KeyState()));
	mKeys.insert(std::make_pair<std::string, KeyState*>("Q", new KeyState()));
	mKeys.insert(std::make_pair<std::string, KeyState*>("S", new KeyState()));
	mKeys.insert(std::make_pair<std::string, KeyState*>("W", new KeyState()));
	mKeys.insert(std::make_pair<std::string, KeyState*>("LSHIFT", new KeyState()));
	mKeys.insert(std::make_pair<std::string, KeyState*>("+", new KeyState()));
	mKeys.insert(std::make_pair<std::string, KeyState*>("-", new KeyState()));
	mKeys.insert(std::make_pair<std::string, KeyState*>("F1", new KeyState()));
	mKeys.insert(std::make_pair<std::string, KeyState*>("F2", new KeyState()));
	mKeys.insert(std::make_pair<std::string, KeyState*>("F3", new KeyState()));
	mKeys.insert(std::make_pair<std::string, KeyState*>("F4", new KeyState()));
}

bool InputController::IsPressed(std::string key)
{
	std::map<std::string, KeyState*>::iterator it = mKeys.find(key);
	if (it != mKeys.end())
	{
		return it->second->IsPressed();
	}
	return false;
}

bool InputController::IsDown(std::string key)
{
	std::map<std::string, KeyState*>::iterator it = mKeys.find(key);
	if (it != mKeys.end())
	{
		return it->second->IsDown();
	}
	return false;
}
bool InputController::Released(std::string key)
{
	std::map<std::string, KeyState*>::iterator it = mKeys.find(key);
	if (it != mKeys.end())
	{
		return it->second->Released();
	}
	return false;
}

KeyState* InputController::GetKey(std::string key)
{
	return mKeys.find(key)->second;
}

std::map<std::string, KeyState*> InputController::GetKeys()
{
	return mKeys;
}