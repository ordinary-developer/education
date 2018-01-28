#include <afxwin.h>

class CMainFrame : public CFrameWnd
{
public:
	CMainFrame ();

protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnActivate(UINT nState,
							CWnd* pWndOther,
							BOOL bMinimized);
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnMove(int x, int y);
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
	ON_WM_SHOWWINDOW()
	ON_WM_ACTIVATE()
	ON_WM_PAINT()
	ON_WM_SIZE()
	ON_WM_MOVE()
END_MESSAGE_MAP()

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct) {
	if (0 == CFrameWnd::OnCreate(lpCreateStruct)) {
		MessageBox(L"The window has been created!");
		return 0;
	}
	return -1;
}

void CMainFrame::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CFrameWnd::OnShowWindow(bShow, nStatus);

	ShowWindow(SW_SHOW);
}

void CMainFrame::OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized) {
	CFrameWnd::OnActivate(nState, pWndOther, bMinimized);

	/*
	switch (nState)
	{
	case WA_ACTIVE:
		MessageBox(L"This window has been activated, without the mouse!");
		break;
	case WA_INACTIVE:
		MessageBox(L"This window has been deactivated and cannot be changed now!!");
		break;
	case WA_CLICKACTIVE:
		MessageBox(L"This window has been activated using the mouse!!!");
		break;
	}*/
}

void CMainFrame::OnPaint() {
	CFrameWnd::OnPaint();

	MessageBox(L"The window has been painted<==>");
}

void CMainFrame::OnSize(UINT nType, int cx, int cy) {
	char* msgToShow = new char[20];
	char* msgCoord = new char[20];

    switch(nType)
	{
    case SIZE_MINIMIZED:
		strcpy(msgToShow, "Minimized ");
		break;
    case SIZE_MAXIMIZED:
		strcpy(msgToShow, "Maximized ");
		break;
    case SIZE_RESTORED:
		strcpy(msgToShow, "Restored ");
		break;
    case SIZE_MAXHIDE:
		strcpy(msgToShow, "Maximized Not Me ");
		break;
    case SIZE_MAXSHOW:
		strcpy(msgToShow, "Restored Not Me ");
		break;
	}
    sprintf(msgCoord, "Left = %d | Top = %d", cx, cy);
    strcat(msgToShow, msgCoord);
	::MessageBoxA(nullptr, msgToShow, "onsize message", 0);
}

void CMainFrame::OnMove(int x, int y) {
	CFrameWnd::OnMove(x, y);

	char* msgCoord = new char[20];
	sprintf(msgCoord, "Left = %d | Top = %d", x, y);
	::MessageBoxA(nullptr, msgCoord, "test", 0);
}

BOOL CExerciseApp::InitInstance()
{
	m_pMainWnd = new CMainFrame ;
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();

	return TRUE;
}

CExerciseApp theApp;