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
	ON_WM_CHAR()
END_MESSAGE_MAP()

CMainWindow::CMainWindow()
{
	Create(nullptr, _T("app"));
} 

void CMainWindow::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if ((nChar >= _T('A') && nChar <= _T('Z')) ||
		(nChar >= _T('a') && nChar <= _T('z')))
	{
		MessageBox(_T("a character was pressed"));
	}
	else if (VK_RETURN == nChar) {
		MessageBox(_T("the Enter button was pressed"));
	}
	else if (VK_BACK == nChar) {
		MessageBox(_T("the Backspace button was pressed"));
	}

}