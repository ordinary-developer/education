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
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

CMainWindow::CMainWindow() {
	Create(nullptr, _T("app example"));
}

void CMainWindow::OnPaint() {

}

void CMainWindow::OnLButtonDown(UINT nFlags, CPoint point) {
	SetCapture();
}

void CMainWindow::OnLButtonUp(UINT nFlags, CPoint point) {
	::ReleaseCapture();
}


