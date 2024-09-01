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

	dc.SetViewportOrg(rect.Width() / 2, rect.Height() / 2);
	dc.SetBkMode(TRANSPARENT);

	for (int i = 0; i < 3600; i += 150) {
		LOGFONT lf;
		::ZeroMemory(&lf, sizeof(lf));
		lf.lfHeight = 160;
		lf.lfWeight = FW_BOLD;
		lf.lfEscapement = i;
		lf.lfOrientation = i;
		::lstrcpy(lf.lfFaceName, _T("Arial"));

		CFont font;
		font.CreatePointFontIndirect(&lf);

		CFont* pOldFont = dc.SelectObject(&font);
		dc.TextOutW(0, 0, CString(_T("    Hello, MFC")));
		dc.SelectObject(pOldFont);
	}
}