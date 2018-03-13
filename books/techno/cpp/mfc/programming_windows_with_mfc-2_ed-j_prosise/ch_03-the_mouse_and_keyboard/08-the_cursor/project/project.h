#pragma once 

#include <afxwin.h>


class CMyApp : public CWinApp {
public:
	virtual BOOL InitInstance() override;
};

class CMainWindow : public CFrameWnd {
public:
	CMainWindow();
	
	HCURSOR m_hArrowCursor;
	HCURSOR m_hIBeamCursor;

protected:
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	DECLARE_MESSAGE_MAP()
};



