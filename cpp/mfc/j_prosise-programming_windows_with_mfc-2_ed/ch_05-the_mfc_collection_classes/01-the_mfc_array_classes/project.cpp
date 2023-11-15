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
	for (int i = 0; i < 10; ++i) 
		uintArray[i] = i + 1;

	std::string uintArrayRepr = "uintArray =>\r\n";
	for (int i = 0; i < 10; ++i)
		uintArrayRepr.append(std::to_string(i)).append(": ").append(std::to_string(uintArray[i])).append("\r\n");
	::MessageBoxA(NULL, uintArrayRepr.c_str(), "test", 0);
}

void CMainWindow::example_02() {
	CStringArray strArray;
	strArray.SetSize(10);
	for (int i = 0; i < 10; ++i) {
		CString str;
		str.Format(_T("%i"), i);
		strArray[i] = str;
	}
	
	std::string strArrayRepr = "strArray =>\r\n";
	for (unsigned int i = 0; i < 10; ++i) {
		CT2CA pszConvertedAnsiString(strArray[i]);
		strArrayRepr.append(std::to_string(i)).append(": ").append(pszConvertedAnsiString).append("\r\n");
	}
	::MessageBoxA(NULL, strArrayRepr.c_str(), "test", 0);
}

void CMainWindow::example_03() {
	CUIntArray uintArray;
	uintArray.SetSize(9);

	for (int i = 0; i < 4; ++i)
		uintArray[i] = i + 1;
	for (int i = 4; i < 9; ++i) 
		uintArray[i] = i + 2;
	
	uintArray.InsertAt(4, 5);

	std::string uintArrayRepr = "uintArray =>\r\n";
	for (int i = 0; i < 10; ++i)
		uintArrayRepr.append(std::to_string(i)).append(": ").append(std::to_string(uintArray[i])).append("\r\n");
	::MessageBoxA(NULL, uintArrayRepr.c_str(), "test", 0);
}

void CMainWindow::example_04() {
	CUIntArray uintArray;
	uintArray.SetSize(10);
	for (unsigned int i = 0; i < 10; ++i) {
		uintArray[i] = i + 1;
	}
	uintArray.RemoveAt(0);
	TRACE(_T("Count = %d\n"), uintArray.GetSize());

	uintArray.RemoveAt(0, 3);
	TRACE(_T("Count = %d\n"), uintArray.GetSize());

	uintArray.RemoveAll();
	TRACE(_T("Count = %d\n"), uintArray.GetSize());
}