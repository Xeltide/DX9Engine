#include "CameraScript.h"

CameraScript::CameraScript(LPDIRECT3DDEVICE9 device, ObjectState* state)
	: ObjectScript::ObjectScript(state)
	, m_pDevice(device)
{
	D3DXVECTOR3 vEyePt(0, 3, -10);
	D3DXVECTOR3 vLookatPt(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 vUpVec(0.0f, 1.0f, 0.0f);
	D3DXMATRIXA16 matView;
	D3DXMatrixLookAtLH(&matView, &vEyePt, &vLookatPt, &vUpVec);
	mState->mTransform.SetMatrix(&matView);
}

void CameraScript::Update(double deltaTime)
{
	// Toggle ambient lighting
	if (mState->mInputController->Released("F1") && mWasReleased)
	{
		if (mAmbientEnabled)
		{
			SetAmbientLight(0x000000);
		}
		else
		{
			SetAmbientLight(0xFFFFFF);
		}
		mAmbientEnabled = !mAmbientEnabled;
		mWasReleased = !mWasReleased;
	} // Toggled lighting repeatedly, this is to lock it to one
	else if (mState->mInputController->IsPressed("F1") && !mWasReleased)
	{
		mWasReleased = true;
	}

	// Selection controls
	if (mState->mInputController->Released("3"))
	{
		mSelected = true;
	}
	else if (mState->mInputController->IsPressed("1") || mState->mInputController->IsPressed("2"))
	{
		mSelected = false;
	}

	// Movement controls
	if (mSelected)
	{
		float speed = 2;
		
		// Rotation controls
		if (mState->mInputController->IsDown("LSHIFT"))
		{
			if (mState->mInputController->IsDown("W"))
			{
				mState->mTransform.Rotate(-speed * deltaTime, 0, 0);
			}
			if (mState->mInputController->IsDown("S"))
			{
				mState->mTransform.Rotate(speed * deltaTime, 0, 0);
			}
			if (mState->mInputController->IsDown("A"))
			{
				mState->mTransform.Rotate(0, -speed * deltaTime, 0);
			}
			if (mState->mInputController->IsDown("D"))
			{
				mState->mTransform.Rotate(0, speed * deltaTime, 0);
			}
			if (mState->mInputController->IsDown("Q"))
			{
				mState->mTransform.Rotate(0, 0, -speed * deltaTime);
			}
			if (mState->mInputController->IsDown("E"))
			{
				mState->mTransform.Rotate(0, 0, speed * deltaTime);
			}
		} // Translate controls
		else
		{
			if (mState->mInputController->IsDown("A"))
			{
				mState->mTransform.Translate(speed * deltaTime, 0, 0);
			}
			if (mState->mInputController->IsDown("D"))
			{
				mState->mTransform.Translate(-speed * deltaTime, 0, 0);
			}
			if (mState->mInputController->IsDown("S"))
			{
				mState->mTransform.Translate(0, speed * deltaTime, 0);
			}
			if (mState->mInputController->IsDown("W"))
			{
				mState->mTransform.Translate(0, -speed * deltaTime, 0);
			}
			if (mState->mInputController->IsDown("-"))
			{
				mState->mTransform.Translate(0, 0, speed * deltaTime);
			}
			if (mState->mInputController->IsDown("+"))
			{
				mState->mTransform.Translate(0, 0, -speed * deltaTime);
			}
		}
	}
}

void CameraScript::SetAmbientLight(int light)
{
	m_pDevice->SetRenderState(D3DRS_AMBIENT, light);
}