#include <afxwin.h>

class CMainFrame : public CFrameWnd
{
public:
    CMainFrame ();
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	DECLARE_MESSAGE_MAP()
};

CMainFrame::CMainFrame()
{
	// Create the window's frame
	Create(NULL, L"Windows Application", WS_OVERLAPPEDWINDOW,
		CRect(120, 100, 700, 480), NULL);
}

class CExerciseApp: public CWinApp
{
public:
	BOOL InitInstance();
};

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
	return -1;
	return 0;
}

void CMainFrame::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) {
	switch (nChar) {
	case VK_RETURN:
		MessageBox(L"You pressed Enter");
		break;
	case VK_F1:
		MessageBox(L"Help is not available at the moment");
		break;
	case VK_DELETE:
		MessageBox(L"Can't Delete this");
		break;
	default:
		MessageBox(L"Whatever");
	}
}

BOOL CExerciseApp::InitInstance()
{
	m_pMainWnd = new CMainFrame ;
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	return TRUE;

	}
CExerciseApp theApp;