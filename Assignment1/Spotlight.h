#pragma once
#include "GameObject.h"
#include "SpotScript.h"

class Spotlight : public GameObject
{
public:
	Spotlight(float xDir, float yDir, float zDir, float x, float y, float z, float r, float g, float b);
	virtual ~Spotlight() = default;
};