#pragma once
#include <d3dx9.h>

class Transform
{
public:
	Transform();
	virtual ~Transform() = default;

	D3DXMATRIXA16 GetMatrix() const;
	void SetMatrix(D3DXMATRIXA16* transform);

	void Translate(float x, float y, float z);
	void Rotate(float x, float y, float z);
private:
	D3DXMATRIXA16 mTransform;
};