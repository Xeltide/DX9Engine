#pragma once
#include "ObjectState.h"
#include "ObjectScript.h"

class GameObject
{
public:
	GameObject();
	GameObject(D3DXMATRIXA16 transform);
	virtual ~GameObject();

	MeshRenderer* const GetMeshRenderer() const;
	void SetMeshRenderer(MeshRenderer* mesh);

	TextRenderer* const GetTextRenderer() const;
	void SetTextRenderer(TextRenderer* text);

	Transform GetTransform() const;

	LightRenderer* const GetLightRenderer() const;
	void SetLightRenderer(LightRenderer* light);

	void SetObjectScript(ObjectScript* objectScript);

	void SetInputController(std::shared_ptr<InputController> inputController);

	void Update(double deltaTime);
protected:
	ObjectScript* mScript;
	ObjectState* mState;
};