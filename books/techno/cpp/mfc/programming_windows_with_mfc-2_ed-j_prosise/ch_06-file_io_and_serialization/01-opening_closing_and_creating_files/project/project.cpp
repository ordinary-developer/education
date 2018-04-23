#include "project.h"

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
	example_03();
	example_04();
	example_05();
	example_06();
}

void CMainWindow::example_01() {
	CFile file;
	CFileException e;
	if (file.Open(_T("File.txt"), CFile::modeReadWrite, &e)) {
		MessageBox(_T("opening is successful"));
	}
	else {
		e.ReportError();
	}
}

void CMainWindow::example_02() {
	try {
		CFile file(_T("File.txt"), CFile::modeReadWrite);
	}
	catch (CFileException* e) {
		e->ReportError();
		e->Delete();
	}
}

void CMainWindow::example_03() {
	CFile file(_T("File.txt"), CFile::modeReadWrite | CFile::modeCreate);
}

void CMainWindow::example_04() {
	CFile file(_T("File.txt"), CFile::modeReadWrite | CFile::modeCreate | CFile::modeNoTruncate);
}

void CMainWindow::example_05() {
	CFile file(_T("File.txt"), CFile::modeReadWrite | CFile::shareDenyWrite);
	file.Close();		 
}

void CMainWindow::example_06() {
	{
		CFile file(_T("File.txt"), CFile::modeReadWrite | CFile::shareDenyWrite);
	}
}