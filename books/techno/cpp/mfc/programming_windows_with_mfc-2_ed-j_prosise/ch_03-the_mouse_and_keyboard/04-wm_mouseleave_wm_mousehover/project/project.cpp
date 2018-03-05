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
	ON_WM_MOUSEMOVE()
	ON_MESSAGE(WM_MOUSELEAVE, OnMouseLeave)
	ON_MESSAGE(WM_MOUSEHOVER, OnMouseHover)
END_MESSAGE_MAP()

CMainWindow::CMainWindow()
	: m_bMouseOver{ FALSE }
{
	Create(nullptr, _T("app example"));
}

void CMainWindow::OnPaint() {

}

void CMainWindow::OnMouseMove(UINT nFlags, CPoint point) {
	if (m_bMouseOver)
		return;

	TRACE(_T("Mouse enter\n"));
	m_bMouseOver = TRUE;

	TRACKMOUSEEVENT trackMouseEvent{};
	trackMouseEvent.cbSize = sizeof(trackMouseEvent);
	trackMouseEvent.dwFlags = TME_HOVER | TME_LEAVE;
	trackMouseEvent.hwndTrack = m_hWnd;
	trackMouseEvent.dwHoverTime = HOVER_DEFAULT;
	::TrackMouseEvent(&trackMouseEvent);

}

LRESULT CMainWindow::OnMouseLeave(WPARAM wParam, LPARAM lParam) {
	TRACE(_T("Mouse leave\n"));
	m_bMouseOver = FALSE;

	return 0;
}

LRESULT CMainWindow::OnMouseHover(WPARAM wParam, LPARAM lParam) {
	TRACE(_T("Mouse hover (x=%d, y=%d)\n"),
		  LOWORD(lParam), HIWORD(lParam));

	TRACKMOUSEEVENT tme{};
	tme.cbSize = sizeof(tme);
	tme.dwFlags = TME_HOVER | TME_LEAVE;
	tme.hwndTrack = m_hWnd;
	tme.dwHoverTime = HOVER_DEFAULT;
	::TrackMouseEvent(&tme);

	return 0;
}

