#pragma once
#include "ObjectScript.h"

class PointScript : public ObjectScript
{
public:
	PointScript(ObjectState* state);
	virtual ~PointScript() = default;

	void Update(double deltaTime);
private:
	bool mLightEnabled = true;
	bool mWasReleased = false;
};