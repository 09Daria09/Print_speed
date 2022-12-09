#pragma once
#include "Header.h"
#include <wchar.h>
#include <winnt.h>

class Level
{
public:
	Level(void);
public:
	static BOOL CALLBACK DlgProc(HWND hWnd, UINT mes, WPARAM wp, LPARAM lp);
	static Level* ptr;
	BOOL Cls_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam);
	void Cls_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify);
	void Cls_OnClose(HWND hwnd);
	~Level(void);
	 TCHAR str[200];
	//TCHAR strL2[200];
};