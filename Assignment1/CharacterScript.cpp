#include "CharacterScript.h"

CharacterScript::CharacterScript(ObjectState* state)
	:ObjectScript::ObjectScript(state)
{
}

void CharacterScript::Update(double deltaTime)
{
	if (mState->mInputController->Released("1"))
	{
		mSelected = true;
	}
	else if (mState->mInputController->IsPressed("2") || mState->mInputController->IsPressed("3"))
	{
		mSelected = false;
	}

	if (mSelected)
	{
		float speed = 2;
		// Rotation controls
		if (mState->mInputController->IsDown("LSHIFT"))
		{
			if (mState->mInputController->IsDown("W"))
			{
				mState->mTransform.Rotate(speed * deltaTime, 0, 0);
			}
			if (mState->mInputController->IsDown("S"))
			{
				mState->mTransform.Rotate(-speed * deltaTime, 0, 0);
			}
			if (mState->mInputController->IsDown("A"))
			{
				mState->mTransform.Rotate(0, -speed * deltaTime, 0);
			}
			if (mState->mInputController->IsDown("D"))
			{
				mState->mTransform.Rotate(0, speed * deltaTime, 0);
			}
			if (mState->mInputController->IsDown("Q"))
			{
				mState->mTransform.Rotate(0, 0, -speed * deltaTime);
			}
			if (mState->mInputController->IsDown("E"))
			{
				mState->mTransform.Rotate(0, 0, speed * deltaTime);
			}
		} // Translate controls
		else
		{
			if (mState->mInputController->IsDown("A"))
			{
				mState->mTransform.Translate(-speed * deltaTime, 0, 0);
			}
			if (mState->mInputController->IsDown("D"))
			{
				mState->mTransform.Translate(speed * deltaTime, 0, 0);
			}
			if (mState->mInputController->IsDown("S"))
			{
				mState->mTransform.Translate(0, -speed * deltaTime, 0);
			}
			if (mState->mInputController->IsDown("W"))
			{
				mState->mTransform.Translate(0, speed * deltaTime, 0);
			}
			if (mState->mInputController->IsDown("-"))
			{
				mState->mTransform.Translate(0, 0, -speed * deltaTime);
			}
			if (mState->mInputController->IsDown("+"))
			{
				mState->mTransform.Translate(0, 0, speed * deltaTime);
			}
		}
	}
}