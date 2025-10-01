#include "hello.h"

#include <math.h>

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
	const int SEGMENTS = 500;
	const double PI = 3.1415926;

	CRect rect{};
	GetClientRect(&rect);
	int nWidth = rect.Width();
	int nHeight = rect.Height();

	CPaintDC dc(this);
	CPoint aPoint[SEGMENTS];

	for (int i{ 0 }; i < SEGMENTS; ++i) {
		aPoint[i].x = (i * nWidth) / SEGMENTS;
		aPoint[i].y = (int)((nHeight / 2) * (1 - sin((2 * PI * i) / SEGMENTS)));
	}
	dc.Polyline(aPoint, SEGMENTS);
}