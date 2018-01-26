#include <afx.h>
#include <afxwin.h>

class CSimpleFrame : public CFrameWnd {
public:
	CSimpleFrame();
	DECLARE_DYNCREATE(CSimpleFrame)

#ifdef _DEBUG
	virtual void AssertValid() const {
		CFrameWnd::AssertValid();
	}

	virtual void Dump(CDumpContext& dc) const {
		CFrameWnd::Dump(dc);
	}
#endif
};

IMPLEMENT_DYNCREATE(CSimpleFrame, CFrameWnd)
CSimpleFrame::CSimpleFrame() {
	Create(nullptr, 
		   L"Windows Application", 
		   WS_OVERLAPPEDWINDOW,
		   CRect(120, 100, 700, 480),
		   nullptr);
}

struct CSimpleApp : public CWinApp {
public:
	BOOL InitInstance() { 
		CSimpleFrame* tester = new CSimpleFrame();
		m_pMainWnd = tester;
		
		m_pMainWnd->ShowWindow(SW_SHOW);
		m_pMainWnd->UpdateWindow();

		return TRUE; 
	}
};

CSimpleApp theApp;