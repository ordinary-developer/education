#include "project.h"

#include "afxtempl.h"

#include <string>
#include <cstddef>

CMyApp myApp;

BOOL CMyApp::InitInstance()
{
	m_pMainWnd = new CMainWindow;

	m_pMainWnd->ShowWindow(m_nCmdShow);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}

BEGIN_MESSAGE_MAP (CMainWindow, CFrameWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

CMainWindow::CMainWindow() {
	Create(nullptr, _T("app example"));
}

void CMainWindow::OnPaint() {

}

void CMainWindow::OnLButtonDown(UINT nFlags, CPoint point) {
	example_01();
	example_02();
}

void CMainWindow::example_01() {
	int a = 5, b = 10;

	CFile file1(_T("example_01"), CFile::modeReadWrite | CFile::modeCreate);
	CArchive ar1(&file1, CArchive::store);
	ar1 << a << b;
	ar1.Close();
	file1.Close();

	CFile file2(_T("example_01"), CFile::modeReadWrite);
	CArchive ar2(&file2, CArchive::load);
	int destA, destB;
	ar2 >> destA >> destB;
	ar2.Close();
	file2.Close();
	MessageBoxA(NULL, std::to_string(destA).c_str(), "test", 0);
	MessageBoxA(NULL, std::to_string(destB).c_str(), "test", 0);
}

void CMainWindow::example_02() {
	CString str = "abc";

	CFile file1(_T("example_02"), CFile::modeReadWrite | CFile::modeCreate);
	CArchive ar1(&file1, CArchive::store);
	ar1 << str;
	ar1.Close();
	file1.Close();

	CString destStr;
	CFile file2(_T("example_02"), CFile::modeRead);
	CArchive ar2(&file2, CArchive::load);
	ar2 >> destStr;
	ar2.Close();
	file2.Close();
	MessageBox(LPCTSTR(destStr));
}
