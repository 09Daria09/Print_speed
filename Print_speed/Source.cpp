#include "Menu.h"

INT WINAPI _tWinMain(HINSTANCE hInst, HINSTANCE hPrev, LPTSTR lpszCmdLine, int nCmdShow)
{
	MSG Msg;
	Menu dlg;
	DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), NULL, Menu::DlgProc);
	BOOL bRet;
	while ((bRet = GetMessage(&Msg, (HWND)NULL, 0, 0)) != 0)
	{
		if (bRet == -1)
		{
			// handle the error and possibly exit
		}
		else
		{
			TranslateMessage(&Msg);
			DispatchMessage(&Msg);
		}
	}
	return 0;
}