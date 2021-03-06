#include "project.h"


CMyApp myApp;

BOOL CMyApp::InitInstance() {
	m_pMainWnd = new CMainWindow;

	m_pMainWnd->ShowWindow(m_nCmdShow);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}

BEGIN_MESSAGE_MAP(CMainWindow, CFrameWnd)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

CMainWindow::CMainWindow() {
	Create(nullptr, _T("The hello application"));
}

void CMainWindow::OnLButtonDown(UINT nFlags, CPoint point) {
	CClientDC dc(this);
	
	dc.MoveTo(0, 0);
	dc.LineTo(0, 100);
	dc.LineTo(100, 100);

	POINT points1[5] = { 0, 0, 0, 100, 100, 100, 100, 0, 0, 0 };
	dc.Polyline(points1, 5);

	dc.MoveTo(0, 0);
	POINT points2[4] = { 0, 100, 100, 100, 100, 0, 0, 0 };
	dc.PolylineTo(points2, 4);
}