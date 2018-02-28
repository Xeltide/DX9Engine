#include "LightRenderer.h"

void LightRenderer::SetDirectional(D3DXVECTOR3 direction, float r, float g, float b)
{
	ZeroMemory(&mLight, sizeof(mLight));
	mVecDir = direction;

	mLight.Type = D3DLIGHT_DIRECTIONAL;
	mLight.Diffuse = D3DXCOLOR(r, g, b, 1.0f);
	D3DXVec3Normalize((D3DXVECTOR3*)&mLight.Direction, &mVecDir);
}

void LightRenderer::SetPoint(D3DXVECTOR3 position, float r, float g, float b)
{
	ZeroMemory(&mLight, sizeof(mLight));

	mLight.Type = D3DLIGHT_POINT;
	mLight.Diffuse = D3DXCOLOR(r, g, b, 1.0f);
	mLight.Position = position;
	mLight.Range = 1000.0f;
	mLight.Attenuation0 = 0.0f;
	mLight.Attenuation1 = 0.0f;
	mLight.Attenuation2 = 0.125f;
}

void LightRenderer::SetSpot(D3DXVECTOR3 direction, D3DXVECTOR3 position, float r, float g, float b)
{
	ZeroMemory(&mLight, sizeof(mLight));
	mLight.Type = D3DLIGHT_SPOT;
	mLight.Diffuse = D3DXCOLOR(r, g, b, 1.0f);
	mLight.Position = position;
	mLight.Direction = direction;
	mLight.Range = 1000.0f;
	mLight.Theta = D3DXToRadian(20.0f);
	mLight.Phi = D3DXToRadian(40.0f);
	mLight.Falloff = 1.0f;
	mLight.Attenuation0 = 0.0f;
	mLight.Attenuation1 = 0.0f;
	mLight.Attenuation2 = 0.125f;
}

void LightRenderer::Load(LPDIRECT3DDEVICE9 device, unsigned int index)
{
	device->SetLight(index, &mLight);
	device->LightEnable(index, TRUE);
	mIndex = index;
	m_pDevice = device;
}

void LightRenderer::SetEnabled(bool enabled)
{
	m_pDevice->LightEnable(mIndex, enabled);
}