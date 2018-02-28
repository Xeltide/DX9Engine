#include "GameObject.h"

GameObject::GameObject()
{
	mState = new ObjectState();
	mScript = new ObjectScript(mState);
}

GameObject::GameObject(D3DXMATRIXA16 transform)
{
	mState = new ObjectState();
	mState->mTransform.SetMatrix(&transform);
	mScript = new ObjectScript(mState);
}

GameObject::~GameObject()
{
	delete mState;
	delete mScript;
}

MeshRenderer* const GameObject::GetMeshRenderer() const
{
	return mState->mMeshRenderer;
}

void GameObject::SetMeshRenderer(MeshRenderer* mesh)
{
	if (mState->mMeshRenderer != nullptr)
	{
		delete mState->mMeshRenderer;
	}
	mState->mMeshRenderer = mesh;
}

TextRenderer* const GameObject::GetTextRenderer() const
{
	return mState->mTextRenderer;
}

void GameObject::SetTextRenderer(TextRenderer* text)
{
	if (mState->mTextRenderer != nullptr)
	{
		delete mState->mTextRenderer;
	}
	mState->mTextRenderer = text;
}

LightRenderer* const GameObject::GetLightRenderer() const
{
	return mState->mLightRenderer;
}

void GameObject::SetLightRenderer(LightRenderer* light)
{
	if (mState->mLightRenderer != nullptr)
	{
		delete mState->mLightRenderer;
	}
	mState->mLightRenderer = light;
}

Transform GameObject::GetTransform() const
{
	return mState->mTransform;
}

void GameObject::SetObjectScript(ObjectScript* objectScript)
{
	delete mScript;
	mScript = objectScript;
}

void GameObject::SetInputController(std::shared_ptr<InputController> inputController)
{
	mState->mInputController = inputController;
}

void GameObject::Update(double deltaTime)
{
	mScript->Update(deltaTime);
}