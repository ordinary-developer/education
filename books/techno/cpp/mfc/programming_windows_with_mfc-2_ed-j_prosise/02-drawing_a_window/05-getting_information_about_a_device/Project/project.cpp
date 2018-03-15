#include "project.h"

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

	char buffer[33];
	CRect rect;

	// getting the width and height of the screen
	int cx = dc.GetDeviceCaps(HORZRES);
	int cy = dc.GetDeviceCaps(VERTRES);
	sprintf(buffer, "width: %d, height: %d", cx, cy);
	::MessageBoxA(nullptr, buffer, "screen sizes", 0);

	// getting the color resoulution of the screen
	int nPlanes = dc.GetDeviceCaps(PLANES);
	int nBPP = dc.GetDeviceCaps(BITSPIXEL);
	long long nColors = ((long long)1 << (long long)(nPlanes * nBPP));
	sprintf(buffer, "color resolution: %lld", nColors);
	::MessageBoxA(nullptr, buffer, "Colore resolution", 0);
}