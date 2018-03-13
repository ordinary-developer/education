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
	ON_WM_SETCURSOR()
END_MESSAGE_MAP()

CMainWindow::CMainWindow()
{
	Create(nullptr, _T("app"));

	m_hArrowCursor = ::LoadCursor(NULL, IDC_ARROW);
	m_hIBeamCursor = ::LoadCursor(NULL, IDC_IBEAM);
} 

BOOL CMainWindow::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) {
	if (HTCLIENT == nHitTest) {
		DWORD dwPos = ::GetMessagePos();
		CPoint point{ LOWORD(dwPos), HIWORD(dwPos) };
		ScreenToClient(&point);
		CRect rect{};
		GetClientRect(&rect);
		::SetCursor((point.y < rect.Height() / 2) ? m_hArrowCursor : m_hIBeamCursor);;;;
		return TRUE;
	}
	return CFrameWnd::OnSetCursor(pWnd, nHitTest, message);
}

