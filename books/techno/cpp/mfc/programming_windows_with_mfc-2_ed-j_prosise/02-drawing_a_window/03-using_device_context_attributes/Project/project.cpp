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

	CRect rect;

	GetClientRect(&rect);
	dc.SetMapMode(MM_ANISOTROPIC);
	dc.SetWindowExt(500, 500);
	dc.SetViewportExt(rect.Width(), rect.Height());
	dc.Ellipse(0, 0, 500, 500);

	GetClientRect(&rect);
	dc.SetMapMode(MM_ISOTROPIC);
	dc.SetWindowExt(500, 500);
	dc.SetViewportExt(rect.Width(), rect.Height());
	dc.Ellipse(0, 0, 500, 500);
}