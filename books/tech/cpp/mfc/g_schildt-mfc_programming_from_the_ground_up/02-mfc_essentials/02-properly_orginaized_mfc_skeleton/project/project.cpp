#include "project.h"


CMainWin::CMainWin() {
	Create(nullptr, _T("An mfc application skeleton"));
}

BOOL CApp::InitInstance() {
	m_pMainWnd = new CMainWin;
	m_pMainWnd->ShowWindow(m_nCmdShow);
	m_pMainWnd->UpdateWindow();

	return TRUE;
}

BEGIN_MESSAGE_MAP(CMainWin, CFrameWnd)
END_MESSAGE_MAP()

CApp app;

