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
	//example_01();
	//example_02();
	example_03();
}

void CMainWindow::example_01() {
	WIN32_FIND_DATA fd;
	HANDLE hFind = ::FindFirstFile(_T("*.*"), &fd);

	if (INVALID_HANDLE_VALUE == hFind)
		return;

	do {
		if (!(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
			TRACE(_T("%s\n"), fd.cFileName);
	} while (::FindNextFile(hFind, &fd));
	::FindClose(hFind);
}

void CMainWindow::example_02() {
	WIN32_FIND_DATA fd;
	HANDLE hFind = ::FindFirstFile(_T("*.*"), &fd);

	if (INVALID_HANDLE_VALUE == hFind)
		return;

	do {
		if (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
			TRACE(_T("%s\n"), fd.cFileName);
	} while (::FindNextFile(hFind, &fd));
}

void EnumerateFolders();
void CMainWindow::example_03() {
	::SetCurrentDirectory(_T("C:\\"));
	EnumerateFolders();
}

void EnumerateFolders() {
	WIN32_FIND_DATA fd;
	HANDLE hFind = ::FindFirstFile(_T("*.*"), &fd);

	if (INVALID_HANDLE_VALUE == hFind) 
		return;

	do {
		if (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
			CString name = fd.cFileName;
			if (_T(".") != name && _T("..") != name) {
				TRACE(_T("%s\n"), fd.cFileName);
				::SetCurrentDirectory(fd.cFileName);
				EnumerateFolders();
				::SetCurrentDirectory(_T(".."));
			}
		}
	} while (::FindNextFile(hFind, &fd));
	::FindClose(hFind);
}