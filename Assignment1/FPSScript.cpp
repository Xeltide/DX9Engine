#include "FPSScript.h"

FPSScript::FPSScript(ObjectState* state)
	: ObjectScript::ObjectScript(state)
{
}

void FPSScript::Update(double deltaTime)
{
	mFrameCount++;
	mTimeSum += deltaTime;

	if (mTimeSum >= 1)
	{
		mFPS = mFrameCount;
		mTimeSum -= 1;
		mFrameCount = 0;
	}

	mState->mTextRenderer->SetText(std::to_string(mFPS));
}