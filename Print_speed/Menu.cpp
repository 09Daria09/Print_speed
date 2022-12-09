#include "Menu.h"
#include"Text.h"
#include "Level.h"

#define WM_ICON WM_APP
#define ID_TRAYICON WM_USER
Menu* Menu::ptr = NULL;

Menu::Menu(void)
{
	ptr = this;
	pNID = new NOTIFYICONDATA;
}

void Menu::Cls_OnClose(HWND hwnd)
{
	EndDialog(hwnd, 0);
}

Menu::~Menu(void)
{
	delete pNID;
}

BOOL Menu::Cls_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam)
{
	HINSTANCE hInst = GetModuleHandle(NULL);
	hIcon = LoadIcon(hInst, MAKEINTRESOURCE(IDI_ICON1));
	hDialog = hwnd;
	SetClassLong(hwnd, GCL_HICON, LONG(hIcon));
	memset(pNID, 0, sizeof(NOTIFYICONDATA));
	pNID->cbSize = sizeof(NOTIFYICONDATA);
	pNID->hIcon = hIcon;
	pNID->hWnd = hwnd;
	pNID->uCallbackMessage = WM_ICON;
	pNID->uFlags = NIF_TIP | NIF_ICON | NIF_MESSAGE | NIF_INFO;
	pNID->uID = ID_TRAYICON;
	return TRUE;
}


void Menu::Cls_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{
	if (id == IDC_EXIT)
	{
		EndDialog(hwnd, 0);
	}
	if (id == IDC_START)
	{
		Text dlg;
		EndDialog(hwnd, 0);
		INT_PTR result = DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(IDD_DIALOG2), hwnd, Text::DlgProc);
	}
}

BOOL CALLBACK Menu::DlgProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		HANDLE_MSG(hwnd, WM_CLOSE, ptr->Cls_OnClose);
		HANDLE_MSG(hwnd, WM_INITDIALOG, ptr->Cls_OnInitDialog);
		HANDLE_MSG(hwnd, WM_COMMAND, ptr->Cls_OnCommand);
	}
	return FALSE;
}
