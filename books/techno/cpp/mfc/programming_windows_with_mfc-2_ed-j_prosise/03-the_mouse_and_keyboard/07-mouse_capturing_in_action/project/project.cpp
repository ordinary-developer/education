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
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_NCLBUTTONDOWN()
END_MESSAGE_MAP()

CMainWindow::CMainWindow() {
	m_bTracking = FALSE;
	m_bCaptureEnabled = TRUE;

	CString strWndClass = AfxRegisterWndClass(0,
											  AfxGetApp()->LoadStandardCursor(IDC_CROSS),
											  (HBRUSH)(COLOR_WINDOW + 1),
											  AfxGetApp()->LoadStandardIcon(IDI_WINLOGO));

	Create(strWndClass, _T("Mouse Capture Demo (Capture Enabled)"));
}

void CMainWindow::OnLButtonDown(UINT nFlags, CPoint point) {
	m_ptFrom = point;
	m_ptTo = point;
	m_bTracking = TRUE;

	if (m_bCaptureEnabled)
		SetCapture();

}

void CMainWindow::OnLButtonUp(UINT nFlags, CPoint point) {
	if (m_bTracking) {
		m_bTracking = FALSE;
		if (GetCapture() == this)
			::ReleaseCapture();

		CClientDC dc(this);
		InvertLine(&dc, m_ptFrom, m_ptTo);

		CPen pen(PS_SOLID, 16, RGB(255, 0, 0));
		dc.SelectObject(&pen);

		dc.MoveTo(m_ptFrom);
		dc.LineTo(point);
	}

}

void CMainWindow::OnMouseMove(UINT nHitTest, CPoint point) {
	if (!m_bTracking)
		return;

	CClientDC dc(this);
	InvertLine(&dc, m_ptFrom, m_ptTo);
	InvertLine(&dc, m_ptFrom, point);
	m_ptTo = point;
}

void CMainWindow::OnNcLButtonDown(UINT nHitTest, CPoint point) {
	if (HTCAPTION == nHitTest) {
		m_bCaptureEnabled = (m_bCaptureEnabled ? FALSE : TRUE);
		SetWindowText(m_bCaptureEnabled
					  ? _T("Mouse Capture Demo (Capture Enabled)")
					  : _T("Mouse Capture Demo (Capture Disabled)"));
	}
	CFrameWnd::OnLButtonDblClk(nHitTest, point);

}

void CMainWindow::InvertLine(CDC* pDC, CPoint ptFrom, CPoint ptTo) {
	int nOldMode = pDC->SetROP2(R2_NOT);
	pDC->MoveTo(ptFrom);
	pDC->LineTo(ptTo);

	pDC->SetROP2(nOldMode);
}
