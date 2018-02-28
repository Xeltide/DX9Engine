#pragma once
#include <d3dx9.h>

class LightRenderer
{
public:
	virtual ~LightRenderer() = default;

	void SetDirectional(D3DXVECTOR3 direction, float r, float g, float b);
	void SetPoint(D3DXVECTOR3 position, float r, float g, float b);
	void SetSpot(D3DXVECTOR3 direction, D3DXVECTOR3 position, float r, float g, float b);

	void Load(LPDIRECT3DDEVICE9 device, unsigned int index);
	void SetEnabled(bool enabled);
private:
	LPDIRECT3DDEVICE9 m_pDevice;
	D3DXVECTOR3 mVecDir;
	D3DLIGHT9 mLight;
	unsigned int mIndex = -1;
};