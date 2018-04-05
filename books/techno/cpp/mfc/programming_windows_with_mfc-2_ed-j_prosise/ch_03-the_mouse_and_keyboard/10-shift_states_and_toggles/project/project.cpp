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
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

CMainWindow::CMainWindow()
{
	Create(nullptr, _T("app"));
} 

void CMainWindow::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	CString tmpStr;

	SHORT shiftKeyState = ::GetKeyState(VK_SHIFT);
	if (shiftKeyState < 0)
		MessageBox(_T("the shift key was pressed"));

	if ((VK_LEFT == nChar) && (::GetKeyState(VK_CONTROL) < 0)) 
		MessageBox(_T("ctrl-left arrow is pressed"));

	if (::GetKeyState(VK_NUMLOCK) & 0x01)
		MessageBox(_T("numlock was pressed"));
}