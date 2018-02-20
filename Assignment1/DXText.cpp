#include "DXText.h"

DXText::DXText(std::string text, LPD3DXFONT font, RECT position, DWORD format, D3DCOLOR fontColour)
	: mText(text)
	, mFont(font)
	, mRect(position)
	, mFormat(format)
	, mFontColour(fontColour)
{

}

DXText::~DXText()
{
	if (mFont != 0)
	{
		mFont->Release();
	}
}

void DXText::SetText(std::string text)
{
	mText = text;
}

void DXText::SetFont(LPD3DXFONT font)
{
	if (mFont != 0)
	{
		mFont->Release();
	}
	mFont = font;
}

bool DXText::Draw()
{
	return mFont->DrawText(NULL, mText.c_str(), -1, &mRect, mFormat, mFontColour) != 0;
}