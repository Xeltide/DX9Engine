#include "Transform.h"

Transform::Transform()
{
	D3DXMatrixTranslation(&mTransform, 0, 0, 0);
}

D3DXMATRIXA16 Transform::GetMatrix() const
{
	return mTransform;
}

void Transform::SetMatrix(D3DXMATRIXA16* transform)
{
	mTransform = *transform;
}

void Transform::Translate(float x, float y, float z)
{
	D3DXMATRIXA16 translation;
	D3DXMatrixTranslation(&translation, x, y, z);
	D3DXMATRIXA16 result;
	D3DXMatrixMultiply(&result, &translation, &mTransform);
	mTransform = result;
}

void Transform::Rotate(float x, float y, float z)
{
	D3DXMATRIXA16 xRotation;
	D3DXMatrixRotationX(&xRotation, x);
	D3DXMATRIXA16 yRotation;
	D3DXMatrixRotationY(&yRotation, y);
	D3DXMATRIXA16 zRotation;
	D3DXMatrixRotationZ(&zRotation, z);
	D3DXMATRIXA16 result;
	D3DXMatrixMultiply(&result, &xRotation, &yRotation);
	D3DXMatrixMultiply(&result, &result, &zRotation);
	D3DXMatrixMultiply(&result, &result, &mTransform);
	mTransform = result;
}