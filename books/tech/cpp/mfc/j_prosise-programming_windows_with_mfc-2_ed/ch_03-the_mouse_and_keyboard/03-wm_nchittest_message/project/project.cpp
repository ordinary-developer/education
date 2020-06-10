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
	ON_WM_NCHITTEST()
END_MESSAGE_MAP()

CMainWindow::CMainWindow() {
	Create(nullptr, _T("app example"));
}

void CMainWindow::OnPaint() {

}

LRESULT CMainWindow::OnNcHitTest(CPoint point) {
	UINT nHitTest = CFrameWnd::OnNcHitTest(point);
	if (HTCLIENT == nHitTest)
		nHitTest = HTCAPTION;
	return nHitTest;
}
