#pragma once
#include "ObjectScript.h"

class CharacterScript : public ObjectScript
{
public:
	CharacterScript(ObjectState* state);
	virtual ~CharacterScript() = default;

	void Update(double deltaTime);
private:
	bool mSelected = true;
};