#include <afxwin.h>

class CMainWin : public CFrameWnd {
public:
	CMainWin();
	DECLARE_MESSAGE_MAP();
};

CMainWin::CMainWin() {
	Create(nullptr, _T("An mfc application skeleton"));
}


class CApp : public CWinApp {
public:
	BOOL InitInstance();
};

BOOL CApp::InitInstance() {
	m_pMainWnd = new CMainWin;
	m_pMainWnd->ShowWindow(m_nCmdShow);
	m_pMainWnd->UpdateWindow();

	return TRUE;
}

BEGIN_MESSAGE_MAP(CMainWin, CFrameWnd)
END_MESSAGE_MAP()

CApp app;

