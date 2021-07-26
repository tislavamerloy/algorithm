#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>
#define UNICODE

#define _WIN32_WINNT 0x0A00

int firstX = 0;
int firstY = 0;
int secondX = 0;
int secondY = 0;
LPPOINT pPnt;
int myFlag = 1;

int r = 0;
int g = 50;
int b = 100;

LRESULT WINAPI WinProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE prevInstance, LPSTR lpCmdLine, int CmdShow) {
	pPnt = malloc(sizeof(*pPnt));

	HWND hDesktop = GetDesktopWindow();
	HDC hDc= GetDC(hDesktop);
	HWND hRText;
	HWND hGText;
	HWND hBText;

	#define CLASS_NAME L"MyWindowClass"
	WNDCLASS wc;
		memset(&wc, 0, sizeof(WNDCLASS));
		wc.lpfnWndProc = WinProc;
		wc.lpszClassName = CLASS_NAME;
		wc.hInstance = hInstance;
	RegisterClass(&wc);

	HWND hwnd;
	hwnd = CreateWindowEx(
		0,
		CLASS_NAME,
		L"Cobloc",
		WS_OVERLAPPEDWINDOW,
		400,400,500,200,
		NULL,NULL,hInstance,NULL
	);

	hRText = CreateWindow(
		L"static",
		L"R",
		WS_VISIBLE | WS_CHILD,
		320, 10, 15, 15,
		hwnd, NULL, hInstance, NULL
	);

	hGText = CreateWindow(
		L"static",
		L"G",
		WS_VISIBLE | WS_CHILD,
		370, 10, 15, 15,
		hwnd, NULL, hInstance, NULL
	);

	hBText = CreateWindow(
		L"static",
		L"B",
		WS_VISIBLE | WS_CHILD,
		420, 10, 15, 15,
		hwnd, NULL, hInstance, NULL
	);

	ShowWindow(hRText, CmdShow);
	ShowWindow(hGText, CmdShow);
	ShowWindow(hBText, CmdShow);
	ShowWindow(hwnd, CmdShow);

	SelectObject(hDc, GetStockObject(DC_BRUSH));
	SetDCBrushColor(hDc, RGB(r, g, b));

	MSG message;
	memset(&message, 0, sizeof(MSG));
	while (1) {
		if (PeekMessage(&message, NULL, 0, 0, PM_REMOVE)) {
			if (message.message == WM_QUIT) break;
			GetCursorPos(pPnt);
			TranslateMessage(&message);
			DispatchMessageW(&message);
		}
		if (firstX != 0 && firstY != 0 && secondX != 0 && secondY != 0)
			Rectangle(hDc, firstX, firstY, secondX, secondY);
		SetDCBrushColor(hDc, RGB(r, g, b));
		if (r < 256) {
			r += 1;
		}else if (g < 256) {
			g += 1;
		}else if (b < 256) {
			b += 1;
		}else {
			r = 10;
			g = 10;
			b = 10;
		}
	}
	return 0;
}

LRESULT WINAPI WinProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {

	switch (message){
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_CHAR:
		if (wParam == L'p') {
			if (myFlag == 3) {
				firstX = 0;
				firstY = 0;
				secondX = 0;
				secondY = 0;
				myFlag = 1;
			} if (myFlag == 1) {
				firstX = pPnt[0].x;
				firstY = pPnt[0].y;
				myFlag += 1;
			} else if (myFlag == 2) {
				secondX = pPnt[0].x;
				secondY = pPnt[0].y;
				myFlag += 1;
			}
		} 
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}

}
