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
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
};


