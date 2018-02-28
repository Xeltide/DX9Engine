#pragma once
#include "GameObject.h"
#include "PointScript.h"

class PointLight : public GameObject
{
public:
	PointLight(float x, float y, float z, float r, float g, float b);
	virtual ~PointLight() = default;
};