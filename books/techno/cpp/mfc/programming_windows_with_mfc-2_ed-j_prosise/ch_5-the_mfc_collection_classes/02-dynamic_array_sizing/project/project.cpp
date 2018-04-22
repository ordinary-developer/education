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
}

void CMainWindow::example_01() {
	CUIntArray uintArray;
	uintArray.SetSize(10);
	for (unsigned int i = 0; i < 10; ++i)
		uintArray[i] = i + 1;

	uintArray.SetSize(20);
	for (unsigned int i = 10; i < 20; ++i) 
		uintArray[i] = i + 1;
}

void CMainWindow::example_02() {
	CUIntArray uintArray;
	for (unsigned int i = 0; i < 10; ++i)
		uintArray.Add(i + 1);
}

void CMainWindow::example_03() {
	try {
		CUIntArray uintArray;
		uintArray.SetSize(1000);
	}
	catch (CMemoryException* e) {
		AfxMessageBox(_T("error: insuficient memory"));
		e->Delete();
	}
}

void CMainWindow::example_04() {
	CUIntArray uintArray;
	uintArray.SetSize(0, 10000);
	for (unsigned int i = 0; i < 10000; ++i) {
		uintArray.Add(i + 1);
	}

	uintArray.SetSize(50);
	uintArray.SetSize(30);
	uintArray.FreeExtra();
}