#include "DirectionalLight.h"

DirectionalLight::DirectionalLight(float x, float y, float z, float r, float g, float b)
	: GameObject::GameObject()
{
	LightRenderer* light = new LightRenderer();
	D3DXVECTOR3 lightDirection = D3DXVECTOR3(x, y, z);
	light->SetDirectional(lightDirection, r, g, b);
	SetLightRenderer(light);
	SetObjectScript(new DirectionalScript(mState));
}