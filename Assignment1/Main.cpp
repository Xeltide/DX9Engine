#include <Windows.h>
#include <iostream>
#include <chrono>
#include "GameWindow.h"
#include "GameEngine.h"

using namespace std::chrono;
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pstrCmdLine, int iCmdShow)
{
	MSG msg;
	GameWindow* window = new GameWindow("Background Render", hInstance);
	GameEngine* engine = new GameEngine();

	if (!window->Register())
	{
		OutputDebugString("Error: Window registration failed.\n");
		// TODO: Error message and close
	}

	if (!window->Create(hInstance))
	{
		OutputDebugString("Error: Window creation failed.\n");
		// TODO: Error message and close
	}

	window->Show(window->GetHwnd(), iCmdShow);

	if (!window->Update(window->GetHwnd()))
	{
		OutputDebugString("Error: Window update failed.\n");
		// TODO: Error message and close
	}

	if (!engine->Init(window->GetHwnd()))
	{
		OutputDebugString("Error: Engine initialization failed.\n");
		// TODO: Error message and close
	}

	auto start = high_resolution_clock::now();
	while (true)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
				break;
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			auto end = high_resolution_clock::now();
			duration<double, milli> dt = end - start;
			start = high_resolution_clock::now();
			engine->Loop(dt.count() / 1000);
		}
	}

	delete engine;
	delete window;
	return msg.wParam;
}