#pragma once
#include "ObjectScript.h"

class CameraScript : public ObjectScript
{
public:
	CameraScript(LPDIRECT3DDEVICE9 device, ObjectState* state);
	virtual ~CameraScript() = default;

	void Update(double deltaTime);
	void SetAmbientLight(int light);
private:
	LPDIRECT3DDEVICE9 m_pDevice;
	bool mAmbientEnabled = false;
	bool mWasReleased = false;
	bool mSelected = false;
};