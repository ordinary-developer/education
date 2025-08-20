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
	CRect rect;
	GetClientRect(&rect);

	CClientDC dc(this);
	dc.MoveTo(rect.left, rect.top);
	dc.LineTo(rect.right, rect.bottom);
	dc.MoveTo(rect.right, rect.top);
	dc.LineTo(rect.left, rect.bottom);
}