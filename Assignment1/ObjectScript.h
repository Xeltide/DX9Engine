#pragma once
#include "ObjectState.h"

class ObjectScript
{
public:
	ObjectScript(ObjectState* state);
	virtual void Update(double deltaTime);
protected:
	ObjectState* mState;
};