#pragma once
#include <d3dx9.h>
#include <string>
/*
SurfaceLoader Class:
- Convenience class for loading surfaces
- May be temporary depending on further use
*/
using namespace std;
class SurfaceLoader
{
public:
	/*
	Use:
	- Loads a surface with an image
	
	Parameters:
	@const string - file path
	@LPDIRECT3DDEVICE9 - the current directX device

	Returns:
	@LPDIRECT3DSURFACE9 - the new surface representing the file
	*/
	static LPDIRECT3DSURFACE9 LoadFromFile(const string, LPDIRECT3DDEVICE9);
};