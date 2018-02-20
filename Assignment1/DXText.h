#pragma once
#include <d3dx9.h>
#include <string>

/*
DXText Class:
- Wrapper class for DirectX fonts allowing for organized text rendering

TODO:
- Convenience and default initializers for text, font
  , position, formatting, and colour
- Setters and getters for font members
*/
class DXText
{
public:
	DXText() = default;
	/*
	Parameters:
	@string - text to render
	@LPD3DXFONT - DirectX font to render with
	@RECT - position to render text at
	@DWORD - DirectX DrawText formatting
	@D3DCOLOR - color of text
	*/
	DXText(std::string, LPD3DXFONT, RECT, DWORD, D3DCOLOR);
	virtual ~DXText();

	/*
	Parameters:
	@string - updated text to render
	*/
	void SetText(std::string);
	/*
	Use:
	- Releases the current font and sets the new one

	Parameters:
	@LPD3DXFONT - new font to render with
	*/
	void SetFont(LPD3DXFONT);
	/*
	Use:
	- Should be called in between DirectX device's
	  BeginScene and EndScene

	Returns:
	@boolean - true if successful draw
	*/
	bool Draw();
private:
	std::string mText;
	LPD3DXFONT mFont = 0;
	RECT mRect;
	DWORD mFormat;
	D3DCOLOR mFontColour;
};