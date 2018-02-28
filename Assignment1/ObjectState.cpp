#include "ObjectState.h"

ObjectState::ObjectState(D3DXMATRIXA16 transform)
{
	mTransform.SetMatrix(&transform);
}

ObjectState::~ObjectState()
{
	delete mTextRenderer;
	delete mMeshRenderer;
}