#include "Controller.h"
#include "PaymentManager.h"

Controller *Controller::ptr = NULL;

Controller::Controller()
{
	ptr = this;
}

Controller ::~Controller()
{}

BOOL CALLBACK Controller::DlgProc(HWND hWnd, UINT mess, WPARAM wParam, LPARAM lParam)
{
	switch (mess)
	{
		HANDLE_MSG(hWnd, WM_INITDIALOG, ptr->Cls_OnInitDialog);
		HANDLE_MSG(hWnd, WM_CLOSE, ptr->Cls_OnClose);
		HANDLE_MSG(hWnd, WM_COMMAND, ptr->Cls_OnCommand);
		HANDLE_MSG(hWnd, WM_TIMER, ptr->Cls_OnTimer);
		HANDLE_MSG(hWnd, WM_HSCROLL, ptr->Cls_OnHScroll);
		HANDLE_MSG(hWnd, WM_VSCROLL, ptr->Cls_OnVScroll);
	}
	return FALSE;
}
BOOL Controller::Cls_OnInitDialog(HWND hWnd, HWND hWndFocus, LPARAM lParam)
{
	//сюда прописать дескрипторы элементов getdlgproc
	hButton1 = GetDlgItem(hWnd, IDOK);
	hButton2 = GetDlgItem(hWnd, IDCANCEL);
	hEdit1 = GetDlgItem(hWnd, IDC_EDIT1);

	hName = GetDlgItem(hWnd, IDC_NAME);
	hNum = GetDlgItem(hWnd, IDC_NUM);
	hSalary = GetDlgItem(hWnd, IDC_SALARY);
	hYear = GetDlgItem(hWnd, IDC_YEAR);
	hP = GetDlgItem(hWnd, IDC_PERCENT);
	hK = GetDlgItem(hWnd, IDC_K);
	hN = GetDlgItem(hWnd, IDC_N);
	hAdd = GetDlgItem(hWnd, IDC_ADD);
	hReset = GetDlgItem(hWnd, IDC_RESET);

	hNum2 = GetDlgItem(hWnd, IDC_NUM2);
	hDel = GetDlgItem(hWnd, IDC_DEL);
	return TRUE;
}
void Controller::Cls_OnCommand(HWND hWnd, int ctrlId, HWND ctrlHandle, UINT codeNotify)
{
	PaymentManager pm;
//прописываем события
	switch (ctrlId)
	{
	case IDC_ADD:
	{
		TCHAR buff[50];
		size_t i;
		GetWindowText(hName, buff, 50);
		
		char buff2[100];
		wcstombs_s(&i, buff2, 100, buff, lstrlen(buff) + 1);
		std::string name = buff2;

		//TCHAR num[20];
		GetWindowText(hNum, buff, 50);
		int num = _wtoi(buff);

		GetWindowText(hSalary, buff, 50);
		double salary = _wtof(buff);

		GetWindowText(hYear, buff, 50);
		int year = _wtoi(buff);

		GetWindowText(hP, buff, 50);
		double p = _wtof(buff);

		GetWindowText(hK, buff, 50);
		int k = _wtoi(buff);

		GetWindowText(hN, buff, 50);
		int N = _wtoi(buff);

		Person x(num, name, salary, year, p, k, N);
		pm.Add(x);
		SetWindowText(hEdit1, pm.Display());
	}

	break;
	case IDC_RESET:
		SetWindowText(hName, L"");
		SetWindowText(hNum, L"");
		SetWindowText(hYear, L"");
		SetWindowText(hSalary, L"");
		SetWindowText(hP, L"");
		SetWindowText(hK, L"");
		SetWindowText(hN, L"");
		break;
	case IDC_DEL:
	{
		TCHAR buff[50];
		GetWindowText(hNum2, buff, 50);
		int num = _wtoi(buff);
		pm.Delete(num);
		SetWindowText(hEdit1, pm.Display());

	}
		break;
	case IDOK:
		SetWindowText(hEdit1, pm.Display());
		break;
	case IDCANCEL:
		EndDialog(hWnd, 0);
		break;
	}
}
void Controller::Cls_OnClose(HWND hWnd)
{
	EndDialog(hWnd, 0);
}
void Controller::Cls_OnTimer(HWND hWnd, UINT timerId)
{}
void Controller::Cls_OnVScroll(HWND hWnd, HWND ctrlHandle, UINT code, int pos)
{}
void Controller::Cls_OnHScroll(HWND hWnd, HWND ctrlHandle, UINT code, int pos)
{}