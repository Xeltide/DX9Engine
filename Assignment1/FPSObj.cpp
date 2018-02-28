#include "FPSObj.h"

FPSObj::FPSObj(LPDIRECT3DDEVICE9 device)
	: GameObject::GameObject()
{
	LPD3DXFONT font;
	D3DXCreateFont(device,     //D3D Device
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
	TextRenderer* text = new TextRenderer(std::string("0"), font, pos, DT_LEFT, D3DCOLOR_XRGB(255, 255, 255));
	SetTextRenderer(text);
	SetObjectScript(new FPSScript(mState));
}