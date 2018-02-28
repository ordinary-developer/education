#include "project.h"

#include <math.h>


#define PI 3.1415926

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

	CBrush brush1(HS_DIAGCROSS, RGB(255, 255, 255));
	dc.SelectObject(&brush1);
	dc.SetBkColor(RGB(192, 192, 192));
    dc.Rectangle(0, 0, 100, 100);

	CBrush brush2(HS_DIAGCROSS, RGB(0, 0, 0));
	dc.SelectObject(&brush2);
	dc.SetBkMode(TRANSPARENT);
	dc.Rectangle(200, 0, 300, 100);

	CBrush brush(RGB(255, 0, 0));
	int x1 = 400, y1 = 0;
	int x2 = 500, y2 = 100;
	CPoint point(x1, y1);
	dc.LPtoDP(&point);
	point.x %= 8;
	point.y %= 8;
	brush.UnrealizeObject();
	dc.SetBrushOrg(point);
	dc.SelectObject(&brush);
	dc.Rectangle(x1, y1, x2, y2);
}