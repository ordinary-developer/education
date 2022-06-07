#pragma once

#include <afxwin.h>


class CMainWin : public CFrameWnd {
public:
	CMainWin();
	DECLARE_MESSAGE_MAP();
};

class CApp : public CWinApp {
public:
	BOOL InitInstance();
};

