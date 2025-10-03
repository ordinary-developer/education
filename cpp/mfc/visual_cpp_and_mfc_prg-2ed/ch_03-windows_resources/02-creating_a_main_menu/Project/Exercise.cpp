#include <afxwin.h>
#include "resource.h"
class CResApp : public CWinApp
{
public:
	BOOL InitInstance();
};

class CResFrame : public CFrameWnd
{
public:
	HACCEL m_hAccel;

	CResFrame()
	{
		m_hAccel = ::LoadAccelerators(AfxGetInstanceHandle(),
						    	      MAKEINTRESOURCE(IDR_ACCELTEST));

		Create(NULL,
			   L"Resources Fundamentals",
			   WS_OVERLAPPEDWINDOW,
			   CRect(200, 120, 640, 400),
			   nullptr,
			   MAKEINTRESOURCE(IDR_MENU_RES));
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