#pragma once
#include <memory>
#include "Transform.h"
#include "MeshRenderer.h"
#include "TextRenderer.h"
#include "LightRenderer.h"
#include "InputController.h"

class ObjectState
{
public:
	ObjectState() = default;
	ObjectState(D3DXMATRIXA16 transform);
	virtual ~ObjectState();

	Transform mTransform;
	MeshRenderer* mMeshRenderer;
	TextRenderer* mTextRenderer;
	LightRenderer* mLightRenderer;
	std::shared_ptr<InputController> mInputController;
};