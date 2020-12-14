// Win32 API tutorial Edit and Static Controls.cpp : This file contains the 'main' function. Program execution begins and ends there.

/*
	Static control can contain text or bitmap
	Static control content cannot be change
	Use as label and give instruction to user

	Edit control can change the content
	Use as user input
*/

#include <iostream>
#include <Windows.h>

#define FILE_MENU_NEW 1
#define FILE_MENU_OPEN 2
#define FILE_MENU_EXIT 3
#define CHANGE_TITLE 4

LRESULT CALLBACK WindowsProcedure(HWND, UINT, WPARAM, LPARAM);

void AddMenus(HWND);

void AddControls(HWND);

HMENU hMenu;
HWND hEdit;

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow)
{
	WNDCLASSW wc = { 0 };
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hInstance = hInst;
	wc.lpszClassName = L"myWindowsClass";
	wc.lpfnWndProc = WindowsProcedure;

	if (!RegisterClassW(&wc))
		return -1;

	CreateWindowW(L"myWindowsClass", L"My Windows", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100, 100, 500, 500, NULL, NULL, NULL, NULL);

	MSG msg = { 0 };

	while (GetMessage(&msg, NULL, NULL, NULL)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}



LRESULT CALLBACK WindowsProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {

	switch (msg)
	{
	case WM_CREATE:
		AddMenus(hWnd);
		AddControls(hWnd);
		break;

	case WM_COMMAND:

		switch (wp)
		{
		case FILE_MENU_EXIT:
			DestroyWindow(hWnd);
			break;
		case FILE_MENU_NEW:
			MessageBox(hWnd, L"New Message", L"Message Template", MB_OK);
			break;
		case FILE_MENU_OPEN:
			MessageBox(hWnd, L"New Open", L"Message Template", MB_OK);
			break;
		case CHANGE_TITLE:
			wchar_t text[100];
			GetWindowTextW(hEdit, text, 90);
			SetWindowTextW(hWnd,text);
			break;
		}

		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProcW(hWnd, msg, wp, lp);
	}

}

void AddMenus(HWND hWnd) {
	hMenu = CreateMenu();

	HMENU hFileMenu = CreateMenu();
	HMENU hSubMenu = CreateMenu();

	//sub menu for open
	AppendMenu(hSubMenu, MF_STRING, NULL, L"Recent Files");
	AppendMenu(hSubMenu, MF_STRING, CHANGE_TITLE, L"Change Title");

	//sub menu for file
	AppendMenu(hFileMenu, MF_STRING, FILE_MENU_NEW, L"New");
	AppendMenu(hFileMenu, MF_POPUP, (UINT_PTR)hSubMenu, L"Open");

	//main menu
	AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hFileMenu, L"File");
	AppendMenu(hMenu, MF_STRING, NULL, L"Help");

	AppendMenu(hFileMenu, MF_SEPARATOR, NULL, NULL);
	AppendMenu(hFileMenu, MF_STRING, FILE_MENU_EXIT, L"Exit");

	SetMenu(hWnd, hMenu);
}


void AddControls(HWND hWnd) {
	CreateWindowW(L"static", L"Enter text here: ", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 200, 100, 100, 50, hWnd, NULL, NULL, NULL);
	hEdit = CreateWindowW(L"Edit", L"",WS_VISIBLE | WS_CHILD | SS_CENTER | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL | EM_GETMODIFY, 200, 152, 100, 50, hWnd, NULL, NULL, NULL);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
