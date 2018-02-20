#include "TestScene.h"
#include "SurfaceLoader.h"

TestScene::TestScene(LPDIRECT3DDEVICE9 device)
	: Scene::Scene(device)
{
	SetBGSurface(SurfaceLoader::LoadFromFile(string(".\\interstellar_skybox\\xpos.bmp"), device));

	LPD3DXFONT font;
	D3DXCreateFont(m_pDevice,     //D3D Device
		40,               //Font height
		12,                //Font width
		FW_NORMAL,        //Font Weight
		1,                //MipLevels
		false,            //Italic
		DEFAULT_CHARSET,  //CharSet
		OUT_DEFAULT_PRECIS, //OutputPrecision
		ANTIALIASED_QUALITY, //Quality
		DEFAULT_PITCH | FF_DONTCARE,//PitchAndFamily
		"Arial",          //pFacename,
		&font);
	RECT pos = { 0, 0, 200, 200 };
	DXText* text = new DXText(string("0"), font, pos, DT_LEFT, D3DCOLOR_XRGB(255, 255, 255));
	PushText(text);

	MeshRenderer* mesh = new MeshRenderer(std::string("tiger.x"));
	mesh->Load(device);
	PushMesh(mesh);
}

TestScene::TestScene(LPDIRECT3DDEVICE9 device, LPDIRECT3DSURFACE9 bgSurface)
	: Scene::Scene(device, bgSurface)
{
}