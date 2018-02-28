#pragma once
#include <string>

#include "GameObject.h"
#include "FPSScript.h"

class FPSObj : public GameObject
{
public:
	FPSObj(LPDIRECT3DDEVICE9 device);
	virtual ~FPSObj() = default;
};