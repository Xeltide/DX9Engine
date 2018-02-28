#include "PlaneObj.h"

PlaneObj::PlaneObj()
	: GameObject::GameObject()
{
	SetMeshRenderer(new MeshRenderer("airplane2.x"));
	SetObjectScript(new CharacterScript2(mState));
}