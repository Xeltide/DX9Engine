#include "GameWindow.h"

unsigned int GameWindow::WIDTH = 1920;
unsigned int GameWindow::HEIGHT = 1080;

GameWindow::GameWindow(std::shared_ptr<InputController> inputController, const char* windowName, HINSTANCE hInstance)
{
	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = sizeof(std::shared_ptr<InputController>);
	wc.lpfnWndProc = WndProc;
	wc.hInstance = hInstance;
	wc.hbrBackground = (HBRUSH)GetStockObject(DKGRAY_BRUSH);
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hIconSm = LoadIcon(NULL, IDI_HAND);
	wc.hCursor = LoadCursor(NULL, IDC_CROSS);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = windowName;

	SetWndClass(wc);
	mInputController = inputController;
}

GameWindow::GameWindow(WNDCLASSEX wndClass)
	: Window::Window(wndClass) {}

BOOL GameWindow::Create(HINSTANCE hInstance)
{
	BOOL result;
	if (HEIGHT != 0 && WIDTH != 0)
	{
		 result = Window::Create(NULL,
			WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			WIDTH, HEIGHT,
			NULL,
			NULL,
			hInstance,
			NULL);
		SetWindowLongPtr(GetHwnd(), 0, (LONG)&*mInputController);
		InputController* temp = (InputController*)GetWindowLongPtr(GetHwnd(), 0);
		return result;
	}
	result = Window::Create(NULL,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		512, 512,
		NULL,
		NULL,
		hInstance,
		NULL);
	SetWindowLongPtr(GetHwnd(), 0, (LONG)&*mInputController);
	return result;
}

long CALLBACK GameWindow::WndProc(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam)
{
	KeyState * key;

	InputController* inputController = (InputController*)GetWindowLongPtr(hWnd, 0);
	if (inputController != nullptr)
	{
		std::map<std::string, KeyState*> keys = inputController->GetKeys();
		for (auto it = keys.begin(); it != keys.end(); it++)
		{
			(*it).second->SetReleased(false);
		}
	}

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
	case WM_KEYDOWN:
		switch (wParam)
		{
		case 0x31: // 1
			key = inputController->GetKey("1");
			if (key->IsPressed() && key->IsDown())
			{
				key->SetIsPressed(false);
			}
			else if (!key->IsPressed() && !key->IsDown())
			{
				key->SetIsPressed(true);
			}
			key->SetIsDown(true);
			break;
		case 0x32: // 2
			key = inputController->GetKey("2");
			if (key->IsPressed() && key->IsDown())
			{
				key->SetIsPressed(false);
			}
			else if (!key->IsPressed() && !key->IsDown())
			{
				key->SetIsPressed(true);
			}
			key->SetIsDown(true);
			break;
		case 0x33: // 3
			key = inputController->GetKey("3");
			if (key->IsPressed() && key->IsDown())
			{
				key->SetIsPressed(false);
			}
			else if (!key->IsPressed() && !key->IsDown())
			{
				key->SetIsPressed(true);
			}
			key->SetIsDown(true);
			break;
		case 0x41: // A
			key = inputController->GetKey("A");
			if (key->IsPressed() && key->IsDown())
			{
				key->SetIsPressed(false);
			}
			else if (!key->IsPressed() && !key->IsDown())
			{
				key->SetIsPressed(true);
			}
			key->SetIsDown(true);
			break;
		case 0x44: // D
			key = inputController->GetKey("D");
			if (key->IsPressed() && key->IsDown())
			{
				key->SetIsPressed(false);
			}
			else if (!key->IsPressed() && !key->IsDown())
			{
				key->SetIsPressed(true);
			}
			key->SetIsDown(true);
			break;
		case 0x45: // E
			key = inputController->GetKey("E");
			if (key->IsPressed() && key->IsDown())
			{
				key->SetIsPressed(false);
			}
			else if (!key->IsPressed() && !key->IsDown())
			{
				key->SetIsPressed(true);
			}
			key->SetIsDown(true);
			break;
		case 0x51: // Q
			key = inputController->GetKey("Q");
			if (key->IsPressed() && key->IsDown())
			{
				key->SetIsPressed(false);
			}
			else if (!key->IsPressed() && !key->IsDown())
			{
				key->SetIsPressed(true);
			}
			key->SetIsDown(true);
			break;
		case 0x53: // S
			key = inputController->GetKey("S");
			if (key->IsPressed() && key->IsDown())
			{
				key->SetIsPressed(false);
			}
			else if (!key->IsPressed() && !key->IsDown())
			{
				key->SetIsPressed(true);
			}
			key->SetIsDown(true);
			break;
		case 0x57: // W
			key = inputController->GetKey("W");
			if (key->IsPressed() && key->IsDown())
			{
				key->SetIsPressed(false);
			}
			else if (!key->IsPressed() && !key->IsDown())
			{
				key->SetIsPressed(true);
			}
			key->SetIsDown(true);
			break;
		case VK_SHIFT: // SHIFT
			key = inputController->GetKey("LSHIFT");
			if (key->IsPressed() && key->IsDown())
			{
				key->SetIsPressed(false);
			}
			else if (!key->IsPressed() && !key->IsDown())
			{
				key->SetIsPressed(true);
			}
			key->SetIsDown(true);
			break;
		case VK_OEM_PLUS: // +
			key = inputController->GetKey("+");
			if (key->IsPressed() && key->IsDown())
			{
				key->SetIsPressed(false);
			}
			else if (!key->IsPressed() && !key->IsDown())
			{
				key->SetIsPressed(true);
			}
			key->SetIsDown(true);
			break;
		case VK_OEM_MINUS: // -
			key = inputController->GetKey("-");
			if (key->IsPressed() && key->IsDown())
			{
				key->SetIsPressed(false);
			}
			else if (!key->IsPressed() && !key->IsDown())
			{
				key->SetIsPressed(true);
			}
			key->SetIsDown(true);
			break;
		case VK_F1: // F1
			key = inputController->GetKey("F1");
			if (key->IsPressed() && key->IsDown())
			{
				key->SetIsPressed(false);
			}
			else if (!key->IsPressed() && !key->IsDown())
			{
				key->SetIsPressed(true);
			}
			key->SetIsDown(true);
			break;
		case VK_F2: // F2
			key = inputController->GetKey("F2");
			if (key->IsPressed() && key->IsDown())
			{
				key->SetIsPressed(false);
			}
			else if (!key->IsPressed() && !key->IsDown())
			{
				key->SetIsPressed(true);
			}
			key->SetIsDown(true);
			break;
		case VK_F3: // F3
			key = inputController->GetKey("F3");
			if (key->IsPressed() && key->IsDown())
			{
				key->SetIsPressed(false);
			}
			else if (!key->IsPressed() && !key->IsDown())
			{
				key->SetIsPressed(true);
			}
			key->SetIsDown(true);
			break;
		case VK_F4: // F4
			key = inputController->GetKey("F4");
			if (key->IsPressed() && key->IsDown())
			{
				key->SetIsPressed(false);
			}
			else if (!key->IsPressed() && !key->IsDown())
			{
				key->SetIsPressed(true);
			}
			key->SetIsDown(true);
			break;
		default:
			break;
		}
		return 0;
	case WM_KEYUP:
		switch (wParam)
		{
		case 0x31: // 1
			key = inputController->GetKey("1");
			key->SetIsPressed(false);
			key->SetIsDown(false);
			key->SetReleased(true);
			break;
		case 0x32: // 2
			key = inputController->GetKey("2");
			key->SetIsPressed(false);
			key->SetIsDown(false);
			key->SetReleased(true);
			break;
		case 0x33: // 3
			key = inputController->GetKey("3");
			key->SetIsPressed(false);
			key->SetIsDown(false);
			key->SetReleased(true);
			break;
		case 0x41: // A
			key = inputController->GetKey("A");
			key->SetIsPressed(false);
			key->SetIsDown(false);
			key->SetReleased(true);
			break;
		case 0x44: // D
			key = inputController->GetKey("D");
			key->SetIsPressed(false);
			key->SetIsDown(false);
			key->SetReleased(true);
			break;
		case 0x45: // E
			key = inputController->GetKey("E");
			key->SetIsPressed(false);
			key->SetIsDown(false);
			key->SetReleased(true);
			break;
		case 0x51: // Q
			key = inputController->GetKey("Q");
			key->SetIsPressed(false);
			key->SetIsDown(false);
			key->SetReleased(true);
			break;
		case 0x53: // S
			key = inputController->GetKey("S");
			key->SetIsPressed(false);
			key->SetIsDown(false);
			key->SetReleased(true);
			break;
		case 0x57: // W
			key = inputController->GetKey("W");
			key->SetIsPressed(false);
			key->SetIsDown(false);
			key->SetReleased(true);
			break;
		case VK_SHIFT: // SHIFT
			key = inputController->GetKey("LSHIFT");
			key->SetIsPressed(false);
			key->SetIsDown(false);
			key->SetReleased(true);
			break;
		case VK_OEM_PLUS: // +
			key = inputController->GetKey("+");
			key->SetIsPressed(false);
			key->SetIsDown(false);
			key->SetReleased(true);
			break;
		case VK_OEM_MINUS: // -
			key = inputController->GetKey("-");
			key->SetIsPressed(false);
			key->SetIsDown(false);
			key->SetReleased(true);
			break;
		case VK_F1: // F1
			key = inputController->GetKey("F1");
			key->SetIsPressed(false);
			key->SetIsDown(false);
			key->SetReleased(true);
			break;
		case VK_F2: // F2
			key = inputController->GetKey("F2");
			key->SetIsPressed(false);
			key->SetIsDown(false);
			key->SetReleased(true);
			break;
		case VK_F3: // F3
			key = inputController->GetKey("F3");
			key->SetIsPressed(false);
			key->SetIsDown(false);
			key->SetReleased(true);
			break;
		case VK_F4: // F4
			key = inputController->GetKey("F4");
			key->SetIsPressed(false);
			key->SetIsDown(false);
			key->SetReleased(true);
			break;
		default:
			break;
		}
		return 0;
	default:
		return DefWindowProc(hWnd, uMessage, wParam, lParam);
	}
}