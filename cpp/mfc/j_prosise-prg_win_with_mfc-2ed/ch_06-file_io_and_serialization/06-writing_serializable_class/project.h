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
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	DECLARE_MESSAGE_MAP()

private:
	void example_01();
};

class CLine : public CObject {
	DECLARE_SERIAL (CLine)

public:
	CLine() {}

	CLine(CPoint from, CPoint to) 
		: m_ptFrom(from), m_ptTo(to) {}

	void Serialize(CArchive& ar);

protected:
	CPoint m_ptFrom;
	CPoint m_ptTo;
};