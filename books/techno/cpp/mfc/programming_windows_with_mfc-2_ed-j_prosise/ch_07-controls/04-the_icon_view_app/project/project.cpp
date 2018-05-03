#include "project.h"

#define IDC_LISTBOX 100

CMyApp myApp;

BOOL CMyApp::InitInstance()
{
	m_pMainWnd = new CMainWindow;
	m_pMainWnd->ShowWindow(m_nCmdShow);
	m_pMainWnd->UpdateWindow();

	return TRUE;
}

BEGIN_MESSAGE_MAP (CMainWindow, CFrameWnd)
	ON_WM_CREATE()
	ON_WM_PAINT()
	ON_WM_SETFOCUS()
	ON_WM_DROPFILES()
	ON_LBN_SELCHANGE(IDC_LISTBOX, OnSelChange)
END_MESSAGE_MAP()

CMainWindow::CMainWindow()
	: m_cxChar(1), m_cyChar(1)
{
	CString strWndClass = AfxRegisterWndClass(
		0,
		myApp.LoadStandardCursor(IDC_ARROW),
		(HBRUSH)(COLOR_3DFACE + 1),
		myApp.LoadStandardIcon(IDI_WINLOGO));

	CreateEx(
		0,
		strWndClass,
		_T("IconView"),
		WS_OVERLAPPED | WS_SYSMENU | WS_CAPTION | WS_MINIMIZEBOX,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, NULL, NULL);

	CRect rect(0, 0, m_cxChar * 84, m_cyChar * 21);
	CalcWindowRect(&rect);

	SetWindowPos(NULL, 0, 0, rect.Width(), rect.Height(), 
		SWP_NOZORDER | SWP_NOMOVE | SWP_NOREDRAW);
}

void CMainWindow::PostNcDestroy() {
	delete this;
}

int CMainWindow::OnCreate(LPCREATESTRUCT lpcs) {
	if (-1 == CWnd::OnCreate(lpcs))
		return -1;

	m_font.CreatePointFont(80, _T("MS Sans Serif"));

	CClientDC dc(this);
	CFont* pOldFont = dc.SelectObject(&m_font);
	TEXTMETRIC tm;
	dc.GetTextMetrics(&tm);
	m_cxChar = tm.tmAveCharWidth;
	m_cyChar = tm.tmHeight + tm.tmExternalLeading;
	dc.SelectObject(pOldFont);

	m_rcImage.SetRect(m_cxChar * 4, m_cyChar * 3, m_cxChar * 46, m_cyChar * 19);

	m_wndGroupBox.Create(
		_T("Detail"),
		WS_CHILD | WS_VISIBLE | BS_GROUPBOX,
		CRect(m_cxChar * 2, m_cyChar, m_cxChar * 48, m_cyChar * 20),
		this,
		(UINT)-1);

	m_wndLabel.Create(
		_T("Icons"),
		WS_CHILD | WS_VISIBLE | SS_LEFT,
		CRect(m_cxChar * 50, m_cyChar, m_cxChar * 82, m_cyChar * 2),
		this);

	m_wndIconListBox.Create(
		WS_CHILD | WS_VISIBLE | WS_VSCROLL | WS_BORDER | LBS_NOTIFY | LBS_NOINTEGRALHEIGHT,
		CRect(m_cxChar * 50, m_cyChar * 2, m_cxChar * 82, m_cyChar * 20),
		this,
		IDC_LISTBOX);

	m_wndGroupBox.SetFont(&m_font);
	m_wndLabel.SetFont(&m_font);
	DragAcceptFiles();

	return 0;
}

void CMainWindow::OnPaint() {
	CPaintDC dc(this);
	m_wndIconListBox.ProjectImage(&dc, m_rcImage, ::GetSysColor(COLOR_3DFACE));
}

void CMainWindow::OnSetFocus(CWnd* pWnd) {
	m_wndIconListBox.SetFocus();	
}

void CMainWindow::OnDropFiles(HDROP hDropInfo) {
	int nCount = ::DragQueryFile(hDropInfo, (UINT)-1, NULL, 0);

	if (1 == nCount) {
		m_wndIconListBox.ResetContent();

		char szFile[MAX_PATH];
		::DragQueryFileA(hDropInfo, 0, szFile, sizeof(szFile));
		int nIcons = (int)::ExtractIconA(NULL, szFile, (UINT)-1);

		if (nIcons) {
			HICON hIcon;
			for (int i = 0; i < nIcons; ++i) {
				hIcon = ::ExtractIconA(AfxGetInstanceHandle(), szFile, i);
				m_wndIconListBox.AddIcon(hIcon);
			}
		}

		CString strWndTitle = szFile;
		strWndTitle += _T(" - IconView");
		SetWindowText(strWndTitle);

		CClientDC dc(this);
		m_wndIconListBox.SetCurSel(0);
		m_wndIconListBox.ProjectImage(&dc, m_rcImage, ::GetSysColor(COLOR_3DFACE));
	}
	::DragFinish(hDropInfo);
}

void CMainWindow::OnSelChange() {
	CClientDC dc(this);
	m_wndIconListBox.ProjectImage(&dc, m_rcImage, ::GetSysColor(COLOR_3DFACE));
}

// region [CIconListBox]
BOOL CIconListBox::PreCreateWindow(CREATESTRUCT& cs) {
	if (!CListBox::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~(CBS_OWNERDRAWVARIABLE | LBS_SORT);
	cs.style |= LBS_OWNERDRAWFIXED;
	return TRUE;
}

void CIconListBox::MeasureItem(LPMEASUREITEMSTRUCT lpmis) {
	lpmis->itemHeight = 36;
}

void CIconListBox::DrawItem(LPDRAWITEMSTRUCT lpdis) {
	CDC dc;
	dc.Attach(lpdis->hDC);
	CRect rect = lpdis->rcItem;
	int nIndex = lpdis->itemID;

	CBrush* pBrush = new CBrush;
	pBrush->CreateSolidBrush(
		::GetSysColor((lpdis->itemState & ODS_SELECTED) ? COLOR_HIGHLIGHT : COLOR_WINDOW));
	dc.FillRect(rect, pBrush);
	delete pBrush;

	if (lpdis->itemState & ODS_FOCUS)
		dc.DrawFocusRect(rect);

	if ((UINT)-1 != nIndex)
		dc.DrawIcon(rect.left + 4, rect.top + 2, (HICON)GetItemData(nIndex));

	dc.Detach();
}

int CIconListBox::AddIcon(HICON hIcon) {
	int nIndex = AddString(_T(""));
	if ((LB_ERR != nIndex) && (LB_ERRSPACE != nIndex))
		SetItemData(nIndex, (DWORD)hIcon);
	return nIndex;
}

void CIconListBox::ProjectImage(CDC* pDC, LPRECT pRect, COLORREF clrBackColor) {
	CDC dcMem;
	dcMem.CreateCompatibleDC(pDC);

	CBitmap bitmap;
	bitmap.CreateCompatibleBitmap(pDC, 32, 32);
	CBitmap* pOldBitmap = dcMem.SelectObject(&bitmap);

	CBrush* pBrush = new CBrush(clrBackColor);
	dcMem.FillRect(CRect(0, 0, 32, 32), pBrush);
	delete pBrush;

	int nIndex = GetCurSel();
	if (LB_ERR != nIndex)
		dcMem.DrawIcon(0, 0, (HICON)GetItemData(nIndex));

	pDC->StretchBlt(pRect->left, pRect->top, pRect->right - pRect->left,
		pRect->bottom - pRect->top, &dcMem, 0, 0, 32, 32, SRCCOPY);
}
// region [CIconListBox]
