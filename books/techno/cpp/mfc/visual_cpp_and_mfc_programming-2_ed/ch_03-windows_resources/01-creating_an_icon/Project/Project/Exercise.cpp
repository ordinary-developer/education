#include <afxwin.h>
#include "resource.h"

class CResApp : public CWinApp
{
public:
	BOOL InitInstance();
};

class CResFrame : public CFrameWnd {
public:
	CResFrame() {
		Create(nullptr, L"Resources fundamentals");
	}
};

BOOL CResApp::InitInstance()
{
	m_pMainWnd = new CResFrame;
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();

	return TRUE;
}

CResApp theApp;