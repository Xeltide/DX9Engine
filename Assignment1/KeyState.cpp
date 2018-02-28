#include "KeyState.h"

void KeyState::SetIsPressed(bool isPressed)
{
	mIsPressed = isPressed;
}

void KeyState::SetIsDown(bool isDown)
{
	mIsDown = isDown;
}

void KeyState::SetReleased(bool released)
{
	mReleased = released;
}

bool KeyState::IsPressed() const
{
	return mIsPressed;
}

bool KeyState::IsDown() const
{
	return mIsDown;
}

bool KeyState::Released() const
{
	return mReleased;
}