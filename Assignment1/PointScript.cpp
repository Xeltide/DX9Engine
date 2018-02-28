#include "PointScript.h"

PointScript::PointScript(ObjectState* state)
	: ObjectScript::ObjectScript(state)
{
}

void PointScript::Update(double deltaTime)
{
	// Toggle ambient lighting
	if (mState->mInputController->Released("F4") && mWasReleased)
	{
		if (mLightEnabled)
		{
			mState->mLightRenderer->SetEnabled(false);
		}
		else
		{
			mState->mLightRenderer->SetEnabled(true);
		}
		mLightEnabled = !mLightEnabled;
		mWasReleased = !mWasReleased;
	} // Toggled lighting repeatedly, this is to lock it to one
	else if (mState->mInputController->IsPressed("F4") && !mWasReleased)
	{
		mWasReleased = true;
	}
}