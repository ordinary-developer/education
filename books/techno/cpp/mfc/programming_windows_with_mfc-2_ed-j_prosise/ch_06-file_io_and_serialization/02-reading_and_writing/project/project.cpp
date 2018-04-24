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
	BYTE buffer[0x1000];
	try {
		CFile file(_T("File.txt"), CFile::modeReadWrite);
		DWORD dwBytesRemaining = file.GetLength();
		while (dwBytesRemaining) {
			DWORD dwPosition = file.GetPosition();
			UINT nBytesRead = file.Read(buffer, sizeof(buffer));
			::CharLowerBuffA((LPSTR)buffer, nBytesRead);
			file.Seek(dwPosition, CFile::begin);
			file.Write(buffer, nBytesRead);
			dwBytesRemaining -= nBytesRead;
		}
	}
	catch (CFileException* e) {
		e->ReportError();
		e->Delete();
	}
}
