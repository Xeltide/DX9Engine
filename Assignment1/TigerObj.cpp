#include "TigerObj.h"

TigerObj::TigerObj()
	: GameObject::GameObject()
{
	SetMeshRenderer(new MeshRenderer("tiger.x"));
	SetObjectScript(new CharacterScript(mState));
}