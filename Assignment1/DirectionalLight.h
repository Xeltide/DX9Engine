#pragma once
#include "GameObject.h"
#include "DirectionalScript.h"

class DirectionalLight : public GameObject
{
public:
	DirectionalLight(float x, float y, float z, float r, float g, float b);
	virtual ~DirectionalLight() = default;
};