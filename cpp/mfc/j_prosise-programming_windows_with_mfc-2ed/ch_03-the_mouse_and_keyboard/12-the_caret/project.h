#pragma once 

#include <afxwin.h>


class CMyApp : public CWinApp {
public:
	virtual BOOL InitInstance() override;
};

class CMainWindow : public CFrameWnd {
public:
	CMainWindow();
	
protected:
	afx_msg void OnSetFocus(CWnd* pWnd);
	afx_msg void OnKillFocus(CWnd* pWnd);
	DECLARE_MESSAGE_MAP()

private:
	int m_cyChar;
	POINT m_ptCaretPos;
};



