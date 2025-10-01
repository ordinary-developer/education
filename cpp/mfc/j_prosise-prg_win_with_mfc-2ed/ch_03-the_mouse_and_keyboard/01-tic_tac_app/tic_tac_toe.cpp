#include "tic_tac_toe.h"

CMyApp app;

BOOL CMyApp::InitInstance() {
	m_pMainWnd = new CMainWindow;
	m_pMainWnd->ShowWindow(m_nCmdShow);
	m_pMainWnd->UpdateWindow();

	return TRUE;
}

BEGIN_MESSAGE_MAP(CMainWindow, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

const CRect CMainWindow::m_rcSquares[9] = {
    CRect ( 16,  16, 112, 112),
    CRect (128,  16, 224, 112),
    CRect (240,  16, 336, 112),
    CRect ( 16, 128, 112, 224),
    CRect (128, 128, 224, 224),
    CRect (240, 128, 336, 224),
    CRect ( 16, 240, 112, 336),
    CRect (128, 240, 224, 336),
    CRect (240, 240, 336, 336)
};

CMainWindow::CMainWindow() {
	m_nNextChar = X_SIGN_VALUE;
	::ZeroMemory(m_nGameGrid, 9 * sizeof(int));

	CString strWndClass =
		AfxRegisterWndClass(CS_DBLCLKS,
							AfxGetApp()->LoadStandardCursor(IDC_ARROW),
							(HBRUSH)(COLOR_3DFACE + 1),
							AfxGetApp()->LoadStandardIcon(IDI_WINLOGO));

	CreateEx(0,
			 strWndClass,
			 _T("Tic-tac-toe"),
			 WS_OVERLAPPED | WS_SYSMENU | WS_CAPTION | WS_MINIMIZEBOX,
			 CW_USEDEFAULT,
			 CW_USEDEFAULT,
			 CW_USEDEFAULT,
			 CW_USEDEFAULT,
			 NULL,
			 NULL);

	CRect rect(0, 0, 352, 352);
	CalcWindowRect(&rect);
	SetWindowPos(NULL, 0, 0, rect.Width(), rect.Height(), SWP_NOZORDER | SWP_NOMOVE | SWP_NOREDRAW);
}

void CMainWindow::PostNcDestroy() {
	delete this;
}

void CMainWindow::OnPaint() {
	CPaintDC dc(this);
	DrawBoard(&dc);
}

void CMainWindow::OnLButtonDown(UINT nFlags, CPoint point) {
	if (X_SIGN_VALUE != m_nNextChar)
		return;

	int nPos = GetRectID(point);
	if (-1 == nPos || 0 != m_nGameGrid[nPos])
		return;

	m_nGameGrid[nPos] = X_SIGN_VALUE;
	m_nNextChar = O_SIGN_VALUE;

	CClientDC dc(this);
	DrawX(&dc, nPos);

	CheckForGameOver();
}

void CMainWindow::OnRButtonDown(UINT nFlags, CPoint point) {
	if (O_SIGN_VALUE != m_nNextChar)
		return;

	int nPos = GetRectID(point);
	if (-1 == nPos || 0 != m_nGameGrid[nPos])
		return;

	m_nGameGrid[nPos] = O_SIGN_VALUE;
	m_nNextChar = X_SIGN_VALUE;

	CClientDC dc(this);
	DrawO(&dc, nPos);
	CheckForGameOver();
}

void CMainWindow::OnLButtonDblClk(UINT nFlags, CPoint point) {
	CClientDC dc(this);
	if (dc.GetPixel(point) == RGB(0, 0, 0))
		ResetGame();
}

int CMainWindow::GetRectID(CPoint point) {
	for (int i = 0; i < 9; ++i)
		if (m_rcSquares[i].PtInRect(point))
			return i;

	return -1;
}

void CMainWindow::DrawBoard(CDC* pDC) {
	CPen pen(PS_SOLID, 16, RGB(0, 0, 0));
	CPen* oldPen = pDC->SelectObject(&pen);

	pDC->MoveTo(120, 16);
	pDC->LineTo(120, 336);

	pDC->MoveTo(232, 16);
	pDC->LineTo(232, 336);

	pDC->MoveTo(16, 120);
	pDC->LineTo(336, 120);

	pDC->MoveTo(16, 232);
	pDC->LineTo(336, 232);

	for (int i = 0; i < 9; ++i)
		if (X_SIGN_VALUE == m_nGameGrid[i])
			DrawX(pDC, i);
		else if (O_SIGN_VALUE == m_nGameGrid[i])
			DrawO(pDC, i);

	pDC->SelectObject(oldPen);
}

void CMainWindow::DrawX(CDC* pDC, int nPos) {
	CPen pen(PS_SOLID, 16, RGB(255, 0, 0));
	CPen* pOldPen = pDC->SelectObject(&pen);

	CRect rect = m_rcSquares[nPos];
	rect.DeflateRect(16, 16);
	pDC->MoveTo(rect.left, rect.top);
	pDC->LineTo(rect.right, rect.bottom);
	pDC->MoveTo(rect.left, rect.bottom);
	pDC->LineTo(rect.right, rect.top);

	pDC->SelectObject(pOldPen);
}

void CMainWindow::DrawO(CDC* pDC, int nPos) {
	CPen pen(PS_SOLID, 16, RGB(0, 0, 255));
	CPen* pOldPen = pDC->SelectObject(&pen);
	pDC->SelectStockObject(NULL_BRUSH);

	CRect rect = m_rcSquares[nPos];
	rect.DeflateRect(16, 16);
	pDC->Ellipse(rect);

	pDC->SelectObject(pOldPen);
}

void CMainWindow::CheckForGameOver() {
	int nWinner = 0;
	CString message;

	if (nWinner = IsWinner()) {
		message = (X_SIGN_VALUE == nWinner
				   ? _T("X wins!")
				   : _T("O wins"));
		MessageBox(message, _T("Game over"), MB_ICONEXCLAMATION | MB_OK);
		ResetGame();
	}
	else if (IsDraw()) {
		MessageBox(_T("It's a draw"), _T("Game over"), MB_ICONEXCLAMATION | MB_OK);
		ResetGame();
	}
}

int CMainWindow::IsWinner() {
	static int nPattern[8][3] = {
		0, 1, 2,
		3, 4, 5,
		6, 7, 8,
		0, 3, 6,
		1, 4, 7,
		2, 5, 8,
		0, 4, 8,
		2, 4, 6
	};

	for (int i = 0; i < 8; ++i) 
		if (m_nGameGrid[nPattern[i][0]] == m_nGameGrid[nPattern[i][1]] &&
			m_nGameGrid[nPattern[i][1]] == m_nGameGrid[nPattern[i][2]])
				return m_nGameGrid[nPattern[i][0]];

	return 0;
}

BOOL CMainWindow::IsDraw() {
	for (int i = 0; i < 9; ++i)
		if (X_SIGN_VALUE != m_nGameGrid[i] && O_SIGN_VALUE != m_nGameGrid[i])
			return FALSE;

	return TRUE;
}

void CMainWindow::ResetGame() {
	m_nNextChar = X_SIGN_VALUE;
	::ZeroMemory(m_nGameGrid, 9 * sizeof(int));
	Invalidate();
}