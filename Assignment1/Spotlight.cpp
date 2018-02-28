#include "Spotlight.h"

Spotlight::Spotlight(float xDir, float yDir, float zDir, float x, float y, float z, float r, float g, float b)
	: GameObject::GameObject()
{
	LightRenderer* light = new LightRenderer();
	D3DXVECTOR3 lightDirection = D3DXVECTOR3(xDir, yDir, zDir);
	D3DXVECTOR3 position = D3DXVECTOR3(x, y, z);
	light->SetSpot(lightDirection, position, r, g, b);
	SetLightRenderer(light);
	SetObjectScript(new SpotScript(mState));
}