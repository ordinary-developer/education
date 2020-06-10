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

	LOGBRUSH lb;
	lb.lbStyle = BS_SOLID;
	lb.lbColor = RGB(0, 255, 0);
	CPen pen(PS_GEOMETRIC | PS_SOLID | PS_ENDCAP_FLAT | PS_JOIN_ROUND,
			 16,
			 &lb);

	dc.SelectObject(&pen);

	dc.BeginPath();
	dc.MoveTo(0, 0);
	dc.LineTo(100, 200);
	dc.LineTo(200, 200);
	dc.CloseFigure();
	dc.EndPath();
	dc.StrokePath();
}