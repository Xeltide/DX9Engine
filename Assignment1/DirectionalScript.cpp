#include "DirectionalScript.h"

DirectionalScript::DirectionalScript(ObjectState* state)
	: ObjectScript::ObjectScript(state)
{
}

void DirectionalScript::Update(double deltaTime)
{
	// Toggle ambient lighting
	if (mState->mInputController->Released("F2") && mWasReleased)
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
	else if (mState->mInputController->IsPressed("F2") && !mWasReleased)
	{
		mWasReleased = true;
	}
}