#include "Header.h"

class Text
{
public:
	Text(void);
public:
	static BOOL CALLBACK DlgProc(HWND hWnd, UINT mes, WPARAM wp, LPARAM lp);
	static Text* ptr;
	void Cls_OnCommand(HWND hwnd, int id, HWND hwndCtl, WPARAM wParam);
	BOOL Cls_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam);
	void Button_change(HWND hwnd, WPARAM wParam, LPTSTR str2);
	void Check(HWND hwnd, WPARAM wParam, LPARAM lParam, LPTSTR str2);
	void Cls_OnClose(HWND hwnd);
	void OnTrayIcon(WPARAM wp, LPARAM lp);
	void Cls_OnSize(HWND hwnd, UINT state, int cx, int cy);
	~Text(void);
	HWND hEditTime, hEditText, hDialog, hEditPoint, hMistakes, hButtonExit;
	HANDLE Time, hMutex;
	static BOOL ForTime;
	static BOOL Simple;
	PNOTIFYICONDATA pNID;
	TCHAR buffer[200];
	LOGFONT lf;
	LOGFONT lf2;
	LOGFONT lf3;
	HFONT hFont;
	HFONT hFont2;
	HFONT hFont3;
	LOGFONT lf4;
	HFONT hFont4;
	COLORREF color;
	static int TIMER;
	static int index;
	static int checkMistake;
	HWND hButton_F, hButton_Q, hButton_W, hButton_E, hButton_R, hButton_T, hButton_Y, hButton_U, hButton_I, hButton_O,
		hButton_P, hButton_A, hButton_S, hButton_D, hButton_G, hButton_H, hButton_J, hButton_K, hButton_L, hButton_Z,
		hButton_X, hButton_C, hButton_V, hButton_B, hButton_N, hButton_M, hButton_SPACE, hButton_EXIT, hButton_TAB, 
		hButton_CL, hButton_SHIFTL, hBitton_CTRLL, hButton_ALTL, hButton_CANCEL, hButton_1, hButton_2, hButton_3, hButton_4,
		hButton_5, hButton_6, hButton_7, hButton_8, hButton_9, hButton_0, hButton_MINUS, hButton_PLUS, hButton_BACK, hButton_BRACKETL,
		hButton_BRACKETR, hButton_SLASH2, hButton_SEMICOLON, hButton_APOSTROPHE, hButton_ENTER, hButton_COMMA, hButton_POINT, hButton_SLASH,
		hButton_SHIFTR, hBitton_CTRLR, hButton_ALTR, hButton_IDOK, hButton_STATIC4, hButton_STATIC1, hButton_STATIC2;
	static BOOL finish;
};