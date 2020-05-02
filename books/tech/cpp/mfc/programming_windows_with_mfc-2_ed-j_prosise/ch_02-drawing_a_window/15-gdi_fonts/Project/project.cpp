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

	CRect rect;
	GetClientRect(&rect);

	CFont font;
	font.CreatePointFont(720, _T("Arial"));

	dc.SelectObject(&font);
	dc.SetBkMode(TRANSPARENT);

	CString string = _T("Hello, MFC");

	rect.OffsetRect(16, 16);
	dc.SetTextColor(RGB(192, 192, 192));
	dc.DrawText(string, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);

	rect.OffsetRect(-16, -16);
	dc.SetTextColor(RGB(0, 0, 0));
	dc.DrawText(string, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
}