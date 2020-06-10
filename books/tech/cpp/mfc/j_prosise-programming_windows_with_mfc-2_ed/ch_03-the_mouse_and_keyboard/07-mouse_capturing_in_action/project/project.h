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
	void InvertLine(CDC* pDC, CPoint ptFrom, CPoint ptTo);

	BOOL m_bTracking;
	BOOL m_bCaptureEnabled;
	CPoint m_ptFrom;
	CPoint m_ptTo;

protected:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnNcLButtonDown(UINT nHitTest, CPoint point);
	DECLARE_MESSAGE_MAP()
};



