#pragma once
#include "Header.h"

class Menu
{
public:
	Menu(void);
public:
	static BOOL CALLBACK DlgProc(HWND hWnd, UINT mes, WPARAM wp, LPARAM lp);
	static Menu* ptr;
	BOOL Cls_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam);
	void Cls_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify);
	void Cls_OnClose(HWND hwnd);
	~Menu(void);
	HICON hIcon;
	HWND hDialog;
	PNOTIFYICONDATA pNID;
};