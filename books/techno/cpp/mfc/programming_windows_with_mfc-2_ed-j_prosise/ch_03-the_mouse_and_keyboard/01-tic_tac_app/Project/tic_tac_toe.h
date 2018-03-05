#pragma once

#include <afxwin.h>

#define X_SIGN_VALUE 1
#define O_SIGN_VALUE 2

class CMyApp : public CWinApp {
public:
	virtual BOOL InitInstance();
};

class CMainWindow : public CWnd {
public:
	CMainWindow();

protected:
	virtual void PostNcDestroy() override;

	int GetRectID(CPoint point);

	void DrawBoard(CDC* pDC);
	void DrawX(CDC* pDC, int nPos);
	void DrawO(CDC* pDC, int nPos);

	void CheckForGameOver();
	int IsWinner();
	BOOL IsDraw();
	void ResetGame();

	int m_nGameGrid[9];
	int m_nNextChar;
	static const CRect m_rcSquares[9];

protected:
	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);

	DECLARE_MESSAGE_MAP()
};

