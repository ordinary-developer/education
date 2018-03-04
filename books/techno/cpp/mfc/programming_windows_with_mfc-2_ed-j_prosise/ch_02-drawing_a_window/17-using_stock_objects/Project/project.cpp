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

	CPen pen1(PS_NULL, 0, RGB(0, 0, 0));
	dc.SelectObject(&pen1);
	CBrush brush2(RGB(192, 192, 192));
	dc.SelectObject(&brush2);
	dc.Ellipse(0, 0, 100, 100);

	dc.SelectStockObject(NULL_PEN);
	dc.SelectStockObject(LTGRAY_BRUSH);
	dc.Ellipse(100, 100, 200, 200);

	CPen pen3;
	pen3.CreateStockObject(NULL_PEN);
	dc.SelectObject(&pen3);
	CBrush brush3;
	brush3.CreateStockObject(LTGRAY_BRUSH);
	dc.SelectObject(&brush3);
	dc.Ellipse(200, 200, 300, 300);
}