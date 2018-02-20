#pragma once
#include <string>
#include "Window.h"

/*
GameWindow Class:
- Convenience class to initiliaze the specific window
  for this game
*/
class GameWindow : public Window
{
public:
	/*
	Parameters:
	@const char* - string to name the current window
	@HINSTANCE - handle to the win main instance
	*/
	GameWindow(const char*, HINSTANCE);
	GameWindow(WNDCLASSEX);
	virtual ~GameWindow() = default;

	// Wrapper to CreateWindowEx
	BOOL Create(HINSTANCE);
	// Handles messages passed to the window
	static long CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

	// Global properties related to the window
	static unsigned int WIDTH;
	static unsigned int HEIGHT;
};