#pragma once
#include "GameObject.h"
#include "CameraScript.h"

class Camera : public GameObject
{
public:
	Camera(LPDIRECT3DDEVICE9 device);
	virtual ~Camera() = default;
};