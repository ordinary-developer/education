#include "project.h"

#include <string>
#include <cstring>


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
	CClientDC dc(this);

	CRect rect;
	CPoint aPoint;
	char buffer[33];

	// getting the center of the window in device coordinates
	GetClientRect(rect);
	aPoint = CPoint(rect.Width() / 2, rect.Height() / 2);
	sprintf(buffer, "x: %d, y: %d", aPoint.x, aPoint.y);
	::MessageBoxA(nullptr, buffer, "test - center of the window", 0);

	// getting the center of the window in MM_LOENGLISH units
	GetClientRect(rect);
	aPoint = CPoint(rect.Width() / 2, rect.Height() / 2);
	dc.SetMapMode(MM_LOENGLISH);
	dc.DPtoLP(&aPoint);
	sprintf(buffer, "x: %d, y: %d", aPoint.x, aPoint.y);
	::MessageBoxA(nullptr, buffer, "test - center of the window in MM_LOENGLISH units", 0);

	// get the pixel coordinates of an arbitrary point
	aPoint = CPoint(100, 100);
	dc.SetMapMode(MM_LOENGLISH);
	dc.LPtoDP(&aPoint);
	sprintf(buffer, "x: %d, y: %d", aPoint.x, aPoint.y);
	::MessageBoxA(nullptr, buffer, "test - center of the window in MM_LOENGLISH units", 0);

	// moving the origin - the 1-st way
	GetClientRect(&rect);
	dc.SetViewportOrg(rect.Width() / 2, rect.Height() / 2);

	// moving the origin - the 2-nd way
	GetClientRect(&rect);
	aPoint = CPoint(rect.Width() / 2, rect.Height() / 2);
	dc.SetMapMode(MM_LOENGLISH);
	dc.DPtoLP(&aPoint);
	dc.SetWindowOrg(-aPoint.x, -aPoint.y);

	// putting the origin to the lower left corner of the window
	GetClientRect(&rect);
	dc.SetViewportOrg(0, rect.Height());
}