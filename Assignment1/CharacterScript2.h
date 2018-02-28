#pragma once
#include "ObjectScript.h"

class CharacterScript2 : public ObjectScript
{
public:
	CharacterScript2(ObjectState* state);
	virtual ~CharacterScript2() = default;

	void Update(double deltaTime);
private:
	bool mSelected = false;
};