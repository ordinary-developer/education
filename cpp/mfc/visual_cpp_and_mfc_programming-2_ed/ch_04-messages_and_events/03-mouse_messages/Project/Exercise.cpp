#include <afxwin.h>

class CMainFrame : public CFrameWnd
{
public:
    CMainFrame ();
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);

	DECLARE_MESSAGE_MAP()
};

CMainFrame::CMainFrame()
{
	// Create the window's frame
	Create(NULL,
		   L"Windows Application", 
		   WS_OVERLAPPEDWINDOW,
	       CRect(120, 100, 700, 480), 
		   NULL);
}

class CExerciseApp: public CWinApp
{
public:
	BOOL InitInstance();
};

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	return 0;
}

void CMainFrame::OnLButtonDown(UINT nFlags, CPoint point)
{
	char* msgCoord = new char[20];
	sprintf(msgCoord, "Left Button at P(%d, %d)", point.x, point.y);
	::MessageBoxA(nullptr, msgCoord, "test", 0);
}

void CMainFrame::OnRButtonUp(UINT nFlags, CPoint point)
{
	const wchar_t* msg = L"This message was sent";
	SendMessage(WM_SETTEXT, 0, (LPARAM)(LPWSTR)msg);
}

BOOL CExerciseApp::InitInstance()
{
	m_pMainWnd = new CMainFrame ;
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();

	return TRUE;
}

CExerciseApp theApp;