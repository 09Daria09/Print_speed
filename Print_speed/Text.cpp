#include "Text.h"
#include "Level.h"
#include"Menu.h"

Text* Text::ptr = NULL;
BOOL Text::ForTime = FALSE;
BOOL Text::Simple = FALSE;
DWORD Priority = GetPriorityClass(GetCurrentProcess());
int Text::index = 0;
int Text::checkMistake = 0;
Level dlg;

typedef map<HWND, TCHAR> MyMap;
typedef MyMap::iterator Iter;

MyMap m;
Iter it;

Text::Text(void)
{
	ptr = this;
}

void Text::Cls_OnClose(HWND hwnd)
{
	EndDialog(hwnd,0);
	TerminateThread(Time, 0);
}

Text::~Text(void)
{
}

DWORD WINAPI Thread(LPVOID lp)
{
	SetPriorityClass(GetCurrentProcess(), ABOVE_NORMAL_PRIORITY_CLASS);
	SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_ABOVE_NORMAL);

	HWND hProgress = (HWND)lp;
	int min = 1;
	int sec = 0;
	TCHAR Time_[255];
	TCHAR Min[255];
	TCHAR Sec[255];
	Text::ForTime = TRUE;
	while (Text::ForTime)
	{
		/*if (sec == 0 && min == 0)
		{
			MessageBox(hProgress, TEXT("Время вышло :("), MB_OK, MB_ICONINFORMATION);
			Text::ForTime = FALSE;
			continue;
		}*/
		sec--;
		if (sec == -1) {
			min--;
			sec = 59;
		}

		if (min < 11)_stprintf_s(Time_, TEXT("0%d"), min);
		else _stprintf_s(Time_, TEXT("%d"), min);

		_stprintf_s(Sec, TEXT(":%d"), sec);
		wcscat_s(Time_, 255, Sec);

		SetWindowText(hProgress, Time_);
		Sleep(980);
	}
	SetPriorityClass(GetCurrentProcess(), Priority);
	ExitThread(Priority);
	return 0;
}

BOOL Text::Cls_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam)
{
	//ShowWindow(hwnd, SW_SHOWMAXIMIZED);
	MSG Msg;
	hDialog = hwnd;

	hMistakes = GetDlgItem(hwnd, IDC_PROGRESS1);
	SendMessage(hMistakes, PBM_SETRANGE, 0, MAKELPARAM(0, 20));
	SendMessage(hMistakes, PBM_SETSTEP, 1, 0);
	SendMessage(hMistakes, PBM_SETPOS, 0, 0);
	SendMessage(hMistakes, PBM_SETBARCOLOR, 0, LPARAM(RGB(0, 215, 0)));
	///

	hEditTime = GetDlgItem(hwnd, IDC_EDIT1);
	Time = CreateThread(NULL, 0, Thread, hEditTime, 0, NULL);
	///

	hEditPoint = GetDlgItem(hwnd, IDC_EDIT3);
	hEditText = GetDlgItem(hwnd, IDC_EDIT2);
	///

	hButton_F = GetDlgItem(hwnd, IDC_F);
	hButton_Q = GetDlgItem(hwnd, IDC_Q);
	hButton_E = GetDlgItem(hwnd, IDC_E);
	hButton_R = GetDlgItem(hwnd, IDC_R);
	hButton_T = GetDlgItem(hwnd, IDC_T);
	hButton_Y = GetDlgItem(hwnd, IDC_Y);
	hButton_U = GetDlgItem(hwnd, IDC_U);
	hButton_I = GetDlgItem(hwnd, IDC_I);
	hButton_O = GetDlgItem(hwnd, IDC_O);
	hButton_P = GetDlgItem(hwnd, IDC_P);
	hButton_A = GetDlgItem(hwnd, IDC_A);
	hButton_S = GetDlgItem(hwnd, IDC_S);
	hButton_D = GetDlgItem(hwnd, IDC_D);
	hButton_G = GetDlgItem(hwnd, IDC_G);
	hButton_H = GetDlgItem(hwnd, IDC_H);
	hButton_J = GetDlgItem(hwnd, IDC_J);
	hButton_K = GetDlgItem(hwnd, IDC_K);
	hButton_L = GetDlgItem(hwnd, IDC_L);
	hButton_Z = GetDlgItem(hwnd, IDC_Z);
	hButton_X = GetDlgItem(hwnd, IDC_X);
	hButton_C = GetDlgItem(hwnd, IDC_C);
	hButton_V = GetDlgItem(hwnd, IDC_V);
	hButton_B = GetDlgItem(hwnd, IDC_B);
	hButton_N = GetDlgItem(hwnd, IDC_N);
	hButton_M = GetDlgItem(hwnd, IDC_M);
	hButton_SPACE = GetDlgItem(hwnd, IDC_SPACE);

	m.insert(pair<HWND, TCHAR>(hButton_F, 'f'));
	m.insert(pair<HWND, TCHAR>(hButton_Q, 'q'));
	m.insert(pair<HWND, TCHAR>(hButton_E, 'e'));
	m.insert(pair<HWND, TCHAR>(hButton_R, 'r'));
	m.insert(pair<HWND, TCHAR>(hButton_T, 't'));
	m.insert(pair<HWND, TCHAR>(hButton_Y, 'y'));
	m.insert(pair<HWND, TCHAR>(hButton_U, 'u'));
	m.insert(pair<HWND, TCHAR>(hButton_I, 'i'));
	m.insert(pair<HWND, TCHAR>(hButton_O, 'o'));
	m.insert(pair<HWND, TCHAR>(hButton_P, 'p'));
	m.insert(pair<HWND, TCHAR>(hButton_A, 'a'));
	m.insert(pair<HWND, TCHAR>(hButton_S, 's'));
	m.insert(pair<HWND, TCHAR>(hButton_D, 'd'));
	m.insert(pair<HWND, TCHAR>(hButton_G, 'g'));
	m.insert(pair<HWND, TCHAR>(hButton_H, 'h'));
	m.insert(pair<HWND, TCHAR>(hButton_J, 'j'));
	m.insert(pair<HWND, TCHAR>(hButton_K, 'k'));
	m.insert(pair<HWND, TCHAR>(hButton_L, 'l'));
	m.insert(pair<HWND, TCHAR>(hButton_Z, 'z'));
	m.insert(pair<HWND, TCHAR>(hButton_X, 'x'));
	m.insert(pair<HWND, TCHAR>(hButton_C, 'c'));
	m.insert(pair<HWND, TCHAR>(hButton_V, 'v'));
	m.insert(pair<HWND, TCHAR>(hButton_B, 'b'));
	m.insert(pair<HWND, TCHAR>(hButton_N, 'n'));
	m.insert(pair<HWND, TCHAR>(hButton_M, 'm'));
	m.insert(pair<HWND, TCHAR>(hButton_SPACE, '@'));

	color = RGB(12, 34, 0);//текущий цвет текста - черный
	memset(&lf, 0, sizeof(lf));//обнуляем структуру LOGFONT
	lf.lfHeight = 33;
	lf.lfWidth = 16;
	hFont = CreateFontIndirect(&lf);//создаём новый шрифт с характеристиками по умолчанию
	SendMessage(hEditText, WM_SETFONT, (WPARAM)hFont, TRUE);
	lf2.lfHeight = 0;
	lf2.lfWidth = 0;
	hFont2 = CreateFontIndirect(&lf2);
	///

	return TRUE;
}
void Text::Button_change(HWND hwnd, WPARAM wParam, LPTSTR str2)
{
	for (int i = 0; i < 200; i++)
	{
		for (Iter it = m.begin(); it != m.end(); it++)
		{
			if (it->second == str2[index] || '@' == it->second && str2[index] == ' ')
			{
				SendMessage(it->first, WM_SETFONT, (WPARAM)hFont, TRUE);
			}
		}
	}
	Simple = TRUE;
}

void Text::Check(HWND hwnd, WPARAM wParam, LPARAM lParam, LPTSTR str2)
{
	for (int i = 0; i < 200; i++)
	{
		for (Iter it = m.begin(); it != m.end(); it++)
		{
			if (it->second == str2[index]|| '@' == it->second && str2[index] == ' ')
			{
				SendMessage(it->first, WM_SETFONT, (WPARAM)hFont2, TRUE);
			}
		}
	}
	TCHAR str[200];
	wsprintf(str, TEXT("%c"), (TCHAR)wParam + 32);	// ASCII-код нажатой клавиши
	SetWindowText(hEditPoint, str);
	if (str[0] == str2[index] || '@' == str[0] && str2[index]==' ')
	{
		str2[index] = '_';
		SetTextColor((HDC)str2[index], RGB(205, 92, 92));
		index++;
		SetWindowText(hEditText, (LPCWSTR)str2);
	}
	else if (str[0] == '1')
	{
		EnableWindow(hwnd, TRUE);
	}
	else
	{
		SendMessage(hMistakes, PBM_STEPIT, 0, 0);
		checkMistake++;
	}


	Simple = FALSE;
}

void Text::Cls_OnCommand(HWND hwnd, int id, HWND hwndCtl, WPARAM wParam)
{
	TCHAR str[200];
	if (id == IDCANCEL)
	{
		if (ForTime == TRUE)
		{
			TerminateThread(Time, 0);
			Time = CreateThread(NULL, 0, Thread, hEditTime, 0, NULL);
		}
		else
		{
			Time = CreateThread(NULL, 0, Thread, hEditTime, 0, NULL);
		}

	}
	if (id == IDOK)
	{
		index = 0;
		INT_PTR result = DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(IDD_DIALOG3), hwnd, Level::DlgProc);
		if (result != NULL)
		{
			EnableWindow(hwnd, NULL);
			SetWindowText(hEditText, dlg.str);
			ptr->Button_change(hwnd, wParam, dlg.str);
		}
		
	}
}

BOOL CALLBACK Text::DlgProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	TCHAR str[200];
	switch (message) {
		HANDLE_MSG(hwnd, WM_CLOSE, ptr->Cls_OnClose);
		HANDLE_MSG(hwnd, WM_INITDIALOG, ptr->Cls_OnInitDialog);
		HANDLE_MSG(hwnd, WM_COMMAND, ptr->Cls_OnCommand);
	}
	if (message == WM_KEYDOWN)
	{
		ptr->Check(hwnd, wParam, lParam, dlg.str);
	}
	if (Simple == FALSE)
	{
		ptr->Button_change(hwnd, wParam, dlg.str);
	}
	if (checkMistake == 20)
	{
		checkMistake = 0;
		MessageBox(hwnd, TEXT("Вы совершили максимальное количество ошибок :("), TEXT("Эх, в следующий раз все получится :) "), MB_OK);
		EndDialog(hwnd, 0);
		//TerminateThread(Time, 0);
	}
	return FALSE;
}
