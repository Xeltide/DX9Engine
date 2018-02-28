#pragma once
#include "ObjectScript.h"

class SpotScript : public ObjectScript
{
public:
	SpotScript(ObjectState* state);
	virtual ~SpotScript() = default;

	void Update(double deltaTime);
private:
	bool mLightEnabled = true;
	bool mWasReleased = false;
};
