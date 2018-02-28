#pragma once
#include "ObjectScript.h"

class DirectionalScript : public ObjectScript
{
public:
	DirectionalScript(ObjectState* state);
	virtual ~DirectionalScript() = default;

	void Update(double deltaTime);
private:
	bool mLightEnabled = true;
	bool mWasReleased = false;
};