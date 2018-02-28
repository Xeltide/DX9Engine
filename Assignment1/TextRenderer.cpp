#include "TextRenderer.h"

TextRenderer::TextRenderer(std::string text, LPD3DXFONT font, RECT position, DWORD format, D3DCOLOR fontColour)
	: mText(text)
	, mFont(font)
	, mRect(position)
	, mFormat(format)
	, mFontColour(fontColour)
{

}

TextRenderer::~TextRenderer()
{
	if (mFont != 0)
	{
		mFont->Release();
	}
}

void TextRenderer::SetText(std::string text)
{
	mText = text;
}

void TextRenderer::SetFont(LPD3DXFONT font)
{
	if (mFont != 0)
	{
		mFont->Release();
	}
	mFont = font;
}

bool TextRenderer::Draw()
{
	return mFont->DrawText(NULL, mText.c_str(), -1, &mRect, mFormat, mFontColour) != 0;
}