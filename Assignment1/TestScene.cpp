#include "TestScene.h"


TestScene::TestScene(LPDIRECT3DDEVICE9 device)
	: Scene::Scene(device)
{
	SetBGSurface(SurfaceLoader::LoadFromFile(string(".\\interstellar_skybox\\xpos.bmp"), device));

	// Camera
	Camera* camera = new Camera(device);
	PushObject(camera);
	// Regular objects
	TigerObj* tiger = new TigerObj();
	PushObject(tiger);
	FPSObj* fps = new FPSObj(device);
	PushObject(fps);
	PlaneObj* plane = new PlaneObj();
	PushObject(plane);
	//Light objects
	DirectionalLight* dirLight = new DirectionalLight(0, 3, 5, 1, 0, 0);
	PushObject(dirLight);
	Spotlight* spotLight = new Spotlight(0, -1, 0, 0, 5, -2, 0, 1, 0);
	PushObject(spotLight);
	PointLight* pointLight = new PointLight(0, -1, -4, 0, 0, 1);
	PushObject(pointLight);
}

TestScene::TestScene(LPDIRECT3DDEVICE9 device, LPDIRECT3DSURFACE9 bgSurface)
	: Scene::Scene(device, bgSurface)
{
}