
// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "Example.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_WM_SETFOCUS()
END_MESSAGE_MAP()

// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// create a view to occupy the client area of the frame
	if (!m_wndView.Create(NULL, NULL, AFX_WS_DEFAULT_VIEW,
		CRect(0, 0, 0, 0), this, AFX_IDW_PANE_FIRST, NULL))
	{
		TRACE0("Failed to create view window\n");
		return -1;
	}

	// region [menu experiments]

	// creating menu
	CMenu menuMain{};
	menuMain.CreateMenu();

	CMenu menuPopup{};
	menuPopup.CreatePopupMenu();
	menuPopup.AppendMenu(MF_STRING, ID_EXAMPLE_1, _T("Example_&1"));
	menuPopup.AppendMenu(MF_STRING, ID_EXAMPLE_2, _T("Example_&2"));
	menuPopup.AppendMenu(MF_STRING, ID_EXAMPLE_3, _T("Example_&3"));
	menuMain.AppendMenu(MF_POPUP, (UINT)menuPopup.Detach(), _T("&Examples"));

	SetMenu(&menuMain);
	menuMain.Detach();

	// deleteing items from a menu
	CMenu* pMenu = GetMenu();
	pMenu->DeleteMenu(ID_EXAMPLE_2, MF_BYCOMMAND);

	// modiyfing an item from a menu
	pMenu = GetMenu();
	pMenu->ModifyMenu(ID_EXAMPLE_3, MF_STRING | MF_BYCOMMAND,
		ID_EXAMPLE_3, _T("new_example_&e"));

	// endregion [menu experiments]
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	cs.style = WS_OVERLAPPED | WS_CAPTION | FWS_ADDTOTITLE
		 | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_SYSMENU;

	cs.dwExStyle &= ~WS_EX_CLIENTEDGE;
	cs.lpszClass = AfxRegisterWndClass(0);
	return TRUE;
}

// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame message handlers

void CMainFrame::OnSetFocus(CWnd* /*pOldWnd*/)
{
	// forward focus to the view window
	m_wndView.SetFocus();
}

BOOL CMainFrame::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo)
{
	// let the view have first crack at the command
	if (m_wndView.OnCmdMsg(nID, nCode, pExtra, pHandlerInfo))
		return TRUE;

	// otherwise, do default handling
	return CFrameWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}

