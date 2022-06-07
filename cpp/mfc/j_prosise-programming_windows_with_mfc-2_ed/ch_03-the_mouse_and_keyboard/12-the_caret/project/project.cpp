#include "project.h"

CMyApp myApp{};

BOOL CMyApp::InitInstance()
{
	m_pMainWnd = new CMainWindow;

	m_pMainWnd->ShowWindow(m_nCmdShow);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}
 BEGIN_MESSAGE_MAP(CMainWindow, CFrameWnd)
	ON_WM_SETFOCUS() 
	ON_WM_KILLFOCUS()
END_MESSAGE_MAP()

CMainWindow::CMainWindow()
	: m_cyChar{ 10 }, m_ptCaretPos{}
{
	Create(nullptr, _T("app"));
} 

void CMainWindow::OnSetFocus(CWnd* pWnd)
{
	CreateSolidCaret(10, m_cyChar);
	SetCaretPos(m_ptCaretPos);
	ShowCaret();
}

void CMainWindow::OnKillFocus(CWnd* pWnd)
{
	HideCaret();
	m_ptCaretPos = GetCaretPos();
	::DestroyCaret();
}
