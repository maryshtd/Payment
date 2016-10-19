#pragma once
#include "Header.h"

class Controller
{
public:
	Controller();
	~Controller();
	static Controller *ptr;
	static BOOL CALLBACK DlgProc(HWND hWnd, UINT mess, WPARAM wParam, LPARAM lParam);
	BOOL Cls_OnInitDialog(HWND hWnd, HWND hWndFocus, LPARAM lParam);
	void Cls_OnCommand(HWND hWnd, int ctrlId, HWND ctrlHandle, UINT codeNotify);
	void Cls_OnClose(HWND hWnd);
	void Cls_OnTimer(HWND hWnd, UINT timerId);
	void Cls_OnVScroll(HWND hWnd, HWND ctrlHandle, UINT code, int pos);
	void Cls_OnHScroll(HWND hWnd, HWND ctrlHandle, UINT code, int pos);
	HWND hButton1, hButton2;
	HWND hEdit1;
	HWND hName, hNum, hSalary, hYear, hP, hK, hN,hAdd,hReset;
	HWND hNum2, hDel;
};