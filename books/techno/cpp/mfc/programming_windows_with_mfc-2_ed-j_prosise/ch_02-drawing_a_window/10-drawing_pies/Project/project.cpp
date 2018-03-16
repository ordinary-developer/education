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

	int nRevenues[4] = { 125, 376, 252, 184 };

	CRect rect;
	GetClientRect(&rect);
	dc.SetViewportOrg(rect.Width() / 2, rect.Height() / 2);
	
	int nTotal = 0;
	for (int i = 0; i < 4; ++i)
		nTotal += nRevenues[i];

	int x1 = 0;
	int y1 = -1000;
	int nSum = 0;

	for (int i = 0; i < 4; ++i) {
		nSum += nRevenues[i];
		double rad = ((double)(nSum * 2 * PI) / (double)nTotal) + PI;
		int x2 = (int)(sin(rad) * 1000);
		int y2 = (int)(cos(rad) * 1000 * 3) / 4;
		dc.Pie(-200, -150, 200, 150, x1, y1, x2, y2);
		x1 = x2;
		y1 = y2;
	}
}