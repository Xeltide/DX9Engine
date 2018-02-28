#pragma once
#include "ObjectScript.h"

class FPSScript : public ObjectScript
{
public:
	FPSScript(ObjectState* state);
	virtual ~FPSScript() = default;

	void Update(double deltaTime);
private:
	unsigned int mFrameCount = 0;
	double mTimeSum = 0;
	unsigned int mFPS = 0;
};