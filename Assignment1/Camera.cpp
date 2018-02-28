#include "Camera.h"

Camera::Camera(LPDIRECT3DDEVICE9 device)
	: GameObject::GameObject()
{
	SetObjectScript(new CameraScript(device, mState));
}