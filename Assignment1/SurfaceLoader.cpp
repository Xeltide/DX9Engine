#include "SurfaceLoader.h"
#include "GameWindow.h"

LPDIRECT3DSURFACE9 SurfaceLoader::LoadFromFile(const string filePath, LPDIRECT3DDEVICE9 device)
{
	// Initialize surface with bitmap dimensions
	LPDIRECT3DSURFACE9 surface;
	device->CreateOffscreenPlainSurface(GameWindow::WIDTH, GameWindow::HEIGHT, D3DFMT_X8R8G8B8, D3DPOOL_SYSTEMMEM, &surface, NULL);

	// Load bitmap onto surface
	D3DXLoadSurfaceFromFile(surface, NULL, NULL, filePath.c_str(), NULL, D3DX_DEFAULT, 0, NULL);

	return surface;
}