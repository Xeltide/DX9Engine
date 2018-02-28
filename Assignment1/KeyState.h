#pragma once
#include <string>

class KeyState
{
public:
	virtual ~KeyState() = default;

	void SetIsPressed(bool isPressed);
	void SetIsDown(bool isDown);
	void SetReleased(bool released);

	bool IsPressed() const;
	bool IsDown() const;
	bool Released() const;
private:
	bool mIsPressed = false;
	bool mIsDown = false;
	bool mReleased = false;
};