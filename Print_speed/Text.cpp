#include "Text.h"
#include "Level.h"
#include"Menu.h"

Text* Text::ptr = NULL;
BOOL Text::ForTime = FALSE;
BOOL Text::Simple = FALSE;
BOOL Text::finish = FALSE;
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
	dlg.Cls_OnClose(hwnd);
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
	int min = 0;
	int sec = 0;
	TCHAR Time_[255];
	TCHAR Min[255];
	TCHAR Sec[255];
	Text::ForTime = TRUE;
	while (Text::ForTime)
	{
		if (min == 5)
		{
			MessageBox(hProgress, TEXT("Что-то вы совсем долго \n Время вышло :("), MB_OK, MB_ICONINFORMATION);
			Text::ForTime = FALSE;
			continue;
		}
		sec++;
		if (sec == 60) {
			min++;
			sec = 0;
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
	hButtonExit = GetDlgItem(hwnd, IDC_10);
	///

	hButton_F = GetDlgItem(hwnd, IDC_F);
	hButton_Q = GetDlgItem(hwnd, IDC_Q);
	hButton_W = GetDlgItem(hwnd, IDC_W);
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
	hButton_EXIT = GetDlgItem(hwnd, IDC_10);
    hButton_TAB = GetDlgItem(hwnd, IDC_TAB);
	hButton_CL = GetDlgItem(hwnd, IDC_CAPSLOCK);
	hButton_SHIFTL = GetDlgItem(hwnd, IDC_SHIFTL);
	hBitton_CTRLL = GetDlgItem(hwnd, IDC_CTRLL);
    hButton_ALTL = GetDlgItem(hwnd, IDC_ALTL);
	hButton_CANCEL = GetDlgItem(hwnd, IDCANCEL);
	hButton_1 = GetDlgItem(hwnd, IDC_1);
	hButton_2 = GetDlgItem(hwnd, IDC_2);
	hButton_3 = GetDlgItem(hwnd, IDC_3);
	hButton_4 = GetDlgItem(hwnd, IDC_4);
	hButton_5 = GetDlgItem(hwnd, IDC_5);
	hButton_6 = GetDlgItem(hwnd, IDC_6);
	hButton_7 = GetDlgItem(hwnd, IDC_7);
	hButton_8 = GetDlgItem(hwnd, IDC_8);
	hButton_9 = GetDlgItem(hwnd, IDC_9);
	hButton_0 = GetDlgItem(hwnd, IDC_NULL);
	hButton_MINUS = GetDlgItem(hwnd, IDC_MINUS);
	hButton_PLUS = GetDlgItem(hwnd, IDC_PLUS);
	hButton_BACK = GetDlgItem(hwnd, IDC_BACK);
	hButton_BRACKETL = GetDlgItem(hwnd, IDC_BRACKETL);
	hButton_BRACKETR = GetDlgItem(hwnd, IDC_BRACKETR);
	hButton_SLASH2 = GetDlgItem(hwnd, IDC_SLASH2);
	hButton_SEMICOLON = GetDlgItem(hwnd, IDC_SEMICOLON);
	hButton_APOSTROPHE = GetDlgItem(hwnd, IDC_APOSTROPHE);
	hButton_ENTER = GetDlgItem(hwnd, IDC_ENTER);
	hButton_COMMA = GetDlgItem(hwnd, IDC_COMMA);
	hButton_POINT = GetDlgItem(hwnd, IDC_POINT);
	hButton_SLASH = GetDlgItem(hwnd, IDC_SLASH);
	hButton_SHIFTR = GetDlgItem(hwnd, IDC_SHIFTR);
	hBitton_CTRLR = GetDlgItem(hwnd, IDC_CTRLR);
	hButton_ALTR = GetDlgItem(hwnd, IDC_ALTR);
	hButton_IDOK = GetDlgItem(hwnd, IDOK);
	hButton_STATIC4 = GetDlgItem(hwnd, IDC_STATIC4);
	hButton_STATIC1 = GetDlgItem(hwnd, IDC_STATIC1);
	hButton_STATIC2 = GetDlgItem(hwnd, IDC_STATIC2);

	m.insert(pair<HWND, TCHAR>(hButton_F, 'f'));
	m.insert(pair<HWND, TCHAR>(hButton_Q, 'q'));
	m.insert(pair<HWND, TCHAR>(hButton_W, 'w'));
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

	lf4.lfHeight = 16;
	lf4.lfWidth = 8;
	hFont4 = CreateFontIndirect(&lf4);

	SendMessage(hButton_STATIC4, WM_SETFONT, (WPARAM)hFont4, TRUE);
	SendMessage(hButton_STATIC1, WM_SETFONT, (WPARAM)hFont4, TRUE);
	SendMessage(hButton_STATIC2, WM_SETFONT, (WPARAM)hFont4, TRUE);

	lf3.lfHeight = 35;
	lf3.lfWidth = 17;
	hFont3 = CreateFontIndirect(&lf3);//создаём новый шрифт с характеристиками по умолчанию
	SendMessage(hEditText, WM_SETFONT, (WPARAM)hFont3, TRUE);


	lf.lfHeight = 60;
	lf.lfWidth = 30;
	hFont = CreateFontIndirect(&lf);//создаём новый шрифт с характеристиками по умолчанию

	lf2.lfHeight = 22;
	lf2.lfWidth = 9;
	hFont2 = CreateFontIndirect(&lf2);
	///
	SendMessage(hButton_Q, WM_SETFONT, (WPARAM)hFont2, TRUE);
	SendMessage(hButton_W, WM_SETFONT, (WPARAM)hFont2, TRUE);
	SendMessage(hButton_E, WM_SETFONT, (WPARAM)hFont2, TRUE);
	SendMessage(hButton_R, WM_SETFONT, (WPARAM)hFont2, TRUE);
	SendMessage(hButton_T, WM_SETFONT, (WPARAM)hFont2, TRUE);
	SendMessage(hButton_Y, WM_SETFONT, (WPARAM)hFont2, TRUE);
	SendMessage(hButton_U, WM_SETFONT, (WPARAM)hFont2, TRUE);
	SendMessage(hButton_I, WM_SETFONT, (WPARAM)hFont2, TRUE);
	SendMessage(hButton_O, WM_SETFONT, (WPARAM)hFont2, TRUE);
	SendMessage(hButton_P, WM_SETFONT, (WPARAM)hFont2, TRUE);
	SendMessage(hButton_A, WM_SETFONT, (WPARAM)hFont2, TRUE);
	SendMessage(hButton_S, WM_SETFONT, (WPARAM)hFont2, TRUE);
	SendMessage(hButton_D, WM_SETFONT, (WPARAM)hFont2, TRUE);
	SendMessage(hButton_F, WM_SETFONT, (WPARAM)hFont2, TRUE);
	SendMessage(hButton_G, WM_SETFONT, (WPARAM)hFont2, TRUE);
	SendMessage(hButton_H, WM_SETFONT, (WPARAM)hFont2, TRUE);
	SendMessage(hButton_J, WM_SETFONT, (WPARAM)hFont2, TRUE);
	SendMessage(hButton_K, WM_SETFONT, (WPARAM)hFont2, TRUE);
	SendMessage(hButton_L, WM_SETFONT, (WPARAM)hFont2, TRUE);
	SendMessage(hButton_Z, WM_SETFONT, (WPARAM)hFont2, TRUE);
	SendMessage(hButton_X, WM_SETFONT, (WPARAM)hFont2, TRUE);
	SendMessage(hButton_C, WM_SETFONT, (WPARAM)hFont2, TRUE);
	SendMessage(hButton_V, WM_SETFONT, (WPARAM)hFont2, TRUE);
	SendMessage(hButton_B, WM_SETFONT, (WPARAM)hFont2, TRUE);
	SendMessage(hButton_N, WM_SETFONT, (WPARAM)hFont2, TRUE);
	SendMessage(hButton_M, WM_SETFONT, (WPARAM)hFont2, TRUE);
	SendMessage(hButton_EXIT, WM_SETFONT, (WPARAM)hFont2, TRUE);
	SendMessage(hButton_TAB, WM_SETFONT, (WPARAM)hFont2, TRUE);
	SendMessage(hButton_CL, WM_SETFONT, (WPARAM)hFont2, TRUE);
	SendMessage(hButton_SHIFTL, WM_SETFONT, (WPARAM)hFont2, TRUE);
	SendMessage(hBitton_CTRLL, WM_SETFONT, (WPARAM)hFont2, TRUE);
	SendMessage(hButton_CANCEL, WM_SETFONT, (WPARAM)hFont2, TRUE);
	SendMessage(hButton_1, WM_SETFONT, (WPARAM)hFont2, TRUE);
	SendMessage(hButton_2, WM_SETFONT, (WPARAM)hFont2, TRUE);
	SendMessage(hButton_3, WM_SETFONT, (WPARAM)hFont2, TRUE);
	SendMessage(hButton_4, WM_SETFONT, (WPARAM)hFont2, TRUE);
	SendMessage(hButton_5, WM_SETFONT, (WPARAM)hFont2, TRUE);
	SendMessage(hButton_6, WM_SETFONT, (WPARAM)hFont2, TRUE);
	SendMessage(hButton_7, WM_SETFONT, (WPARAM)hFont2, TRUE);
	SendMessage(hButton_8, WM_SETFONT, (WPARAM)hFont2, TRUE);
	SendMessage(hButton_9, WM_SETFONT, (WPARAM)hFont2, TRUE);
	SendMessage(hButton_0, WM_SETFONT, (WPARAM)hFont2, TRUE);
	SendMessage(hButton_MINUS, WM_SETFONT, (WPARAM)hFont2, TRUE);
	SendMessage(hButton_PLUS, WM_SETFONT, (WPARAM)hFont2, TRUE);
	SendMessage(hButton_BACK, WM_SETFONT, (WPARAM)hFont2, TRUE);
	SendMessage(hButton_BRACKETL, WM_SETFONT, (WPARAM)hFont2, TRUE);
	SendMessage(hButton_BRACKETR, WM_SETFONT, (WPARAM)hFont2, TRUE);
	SendMessage(hButton_SLASH2, WM_SETFONT, (WPARAM)hFont2, TRUE);
	SendMessage(hButton_SEMICOLON, WM_SETFONT, (WPARAM)hFont2, TRUE);
	SendMessage(hButton_APOSTROPHE, WM_SETFONT, (WPARAM)hFont2, TRUE);
	SendMessage(hButton_COMMA, WM_SETFONT, (WPARAM)hFont2, TRUE);
	SendMessage(hButton_POINT, WM_SETFONT, (WPARAM)hFont2, TRUE);
	SendMessage(hButton_SLASH, WM_SETFONT, (WPARAM)hFont2, TRUE);
	SendMessage(hButton_SPACE, WM_SETFONT, (WPARAM)hFont2, TRUE);
	SendMessage(hButton_ENTER, WM_SETFONT, (WPARAM)hFont2, TRUE);
	SendMessage(hButton_SHIFTR, WM_SETFONT, (WPARAM)hFont2, TRUE);
	SendMessage(hBitton_CTRLR, WM_SETFONT, (WPARAM)hFont2, TRUE);
	SendMessage(hButton_ALTR, WM_SETFONT, (WPARAM)hFont2, TRUE);
	SendMessage(hButton_IDOK, WM_SETFONT, (WPARAM)hFont2, TRUE);
	SendMessage(hButton_ALTL, WM_SETFONT, (WPARAM)hFont2, TRUE);

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
		index++;
		SetWindowText(hEditText, (LPCWSTR)str2);
		if (index == 200)
		{
			finish = TRUE;
		}
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
	if (id == IDC_10)
	{
		EndDialog(hwnd, IDC_10);
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
	if (finish == TRUE)
	{
		finish = FALSE;
		MessageBox(hwnd, TEXT("133 слова в минуту "),TEXT("Результат"),MB_OK);
	}
	return FALSE;
}
