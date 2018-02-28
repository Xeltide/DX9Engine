#include "PointLight.h"

PointLight::PointLight(float x, float y, float z, float r, float g, float b)
	: GameObject::GameObject()
{
	LightRenderer* light = new LightRenderer();
	D3DXVECTOR3 position = D3DXVECTOR3(x, y, z);
	light->SetPoint(position, r, g, b);
	SetLightRenderer(light);
	SetObjectScript(new PointScript(mState));
}