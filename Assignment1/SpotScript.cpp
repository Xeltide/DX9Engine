#include "SpotScript.h"

SpotScript::SpotScript(ObjectState* state)
	: ObjectScript::ObjectScript(state)
{
}

void SpotScript::Update(double deltaTime)
{
	// Toggle ambient lighting
	if (mState->mInputController->Released("F3") && mWasReleased)
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
	else if (mState->mInputController->IsPressed("F3") && !mWasReleased)
	{
		mWasReleased = true;
	}
}