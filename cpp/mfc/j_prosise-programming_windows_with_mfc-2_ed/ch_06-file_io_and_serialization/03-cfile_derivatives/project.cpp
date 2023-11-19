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
}

void CMainWindow::example_01() {
	try {
		CString str;
		CStdioFile file(_T("File.txt"), CFile::modeRead);
		while (file.ReadString(str))
			TRACE(_T("%s\n"), str);
	}
	catch (CFileException* e) {
		e->ReportError();
		e->Delete();
	}
}
