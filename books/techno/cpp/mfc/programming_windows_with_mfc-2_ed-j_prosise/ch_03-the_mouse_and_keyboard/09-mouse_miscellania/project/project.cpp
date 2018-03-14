#include "project.h"

CMyApp myApp{};

BOOL CMyApp::InitInstance()
{
	m_pMainWnd = new CMainWindow;

	m_pMainWnd->ShowWindow(m_nCmdShow);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}

BEGIN_MESSAGE_MAP (CMainWindow, CFrameWnd)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

CMainWindow::CMainWindow()
{
	Create(nullptr, _T("app"));
} 

void CMainWindow::OnLButtonDown(UINT nFlags, CPoint point) {
	CString valueRepr{};

	int mouseInfo = ::GetSystemMetrics(SM_CMOUSEBUTTONS);
	int mousePresentInfo = ::GetSystemMetrics(SM_MOUSEPRESENT);
	valueRepr.Format(_T("SM_CMOUSEBUTTONS:%i;SM_MOUSEPRESENT:%i"), mouseInfo, mousePresentInfo);
	MessageBox((LPCTSTR)valueRepr);

	UINT srcDoubleClickTime{ ::GetDoubleClickTime() };
	::SetDoubleClickTime(500);
	UINT modifiedDoubleClickTime{ ::GetDoubleClickTime() };
	::SetDoubleClickTime(srcDoubleClickTime);
	valueRepr.Format(_T("srcDoubleClickTime:%u;modifiedDoubleClickTime:%u"), srcDoubleClickTime, modifiedDoubleClickTime);
	MessageBox((LPCTSTR)valueRepr);

	SHORT leftButtonState = ::GetAsyncKeyState(VK_LBUTTON);
	SHORT rightButtonState = ::GetAsyncKeyState(VK_RBUTTON);
	SHORT auxLeftButtonState = ::GetAsyncKeyState(VK_LBUTTON);
	UINT sm_swapbuttonInfo = ::GetSystemMetrics(SM_SWAPBUTTON);
	SHORT buttonState = (sm_swapbuttonInfo) ? rightButtonState : leftButtonState;
	valueRepr.Format(_T("leftButtonState:%i;rightButtonState:%i;auxLeftButtonState:%i;sm_swapbuttonInfo:%i;buttonState:%i"),
					 leftButtonState, rightButtonState, auxLeftButtonState, sm_swapbuttonInfo, leftButtonState, buttonState);
	MessageBox((LPCTSTR)valueRepr);
}