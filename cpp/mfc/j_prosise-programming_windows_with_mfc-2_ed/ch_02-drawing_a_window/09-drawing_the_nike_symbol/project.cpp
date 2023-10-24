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
END_MESSAGE_MAP()

CMainWindow::CMainWindow() {
	Create(nullptr, _T("The Hello Application"));
}

void CMainWindow::OnPaint() {
	CPaintDC dc(this);

	POINT points1[4] = { 120, 100, 120, 200, 250, 150, 500, 40 };
	POINT points2[4] = { 120, 100, 50, 350, 250, 200, 500, 40 };
	dc.PolyBezier(points1, 4);
	dc.PolyBezier(points2, 4);
}