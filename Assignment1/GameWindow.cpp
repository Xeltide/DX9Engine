#include "GameWindow.h"

unsigned int GameWindow::WIDTH = 1920;
unsigned int GameWindow::HEIGHT = 1080;

GameWindow::GameWindow(const char* windowName, HINSTANCE hInstance)
{
	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.lpfnWndProc = WndProc;
	wc.hInstance = hInstance;
	wc.hbrBackground = (HBRUSH)GetStockObject(DKGRAY_BRUSH);
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hIconSm = LoadIcon(NULL, IDI_HAND);
	wc.hCursor = LoadCursor(NULL, IDC_CROSS);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = windowName;

	SetWndClass(wc);
}

GameWindow::GameWindow(WNDCLASSEX wndClass)
	: Window::Window(wndClass) {}

BOOL GameWindow::Create(HINSTANCE hInstance)
{
	if (HEIGHT != 0 && WIDTH != 0)
	{
		return Window::Create(NULL,
			WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			WIDTH, HEIGHT,
			NULL,
			NULL,
			hInstance,
			NULL);
	}
	return Window::Create(NULL,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		512, 512,
		NULL,
		NULL,
		hInstance,
		NULL);
}

long CALLBACK GameWindow::WndProc(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam)
{
	switch (uMessage)
	{
	case WM_CREATE:
		return 0;
	case WM_PAINT:
		ValidateRect(hWnd, NULL);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	default:
		return DefWindowProc(hWnd, uMessage, wParam, lParam);
	}
}