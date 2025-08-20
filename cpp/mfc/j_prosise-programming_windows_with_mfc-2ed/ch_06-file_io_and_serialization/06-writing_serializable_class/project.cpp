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
}

void CMainWindow::example_01() {
	const std::size_t COUNT = 3;
	CLine* pLines[COUNT] = { new CLine(5, 10), new CLine(15, 20), new CLine(25, 30) };

	{
		CFile storeFile(_T("example_01"), CFile::modeWrite | CFile::modeCreate);
		CArchive storeAr(&storeFile, CArchive::store);

		storeAr << COUNT;
		for (std::size_t i = 0; i < COUNT; ++i)
			storeAr << pLines[i];
	}

	{
		CFile loadFile(_T("example_01"), CFile::modeRead);
		CArchive loadAr(&loadFile, CArchive::load);

		std::size_t destCount = 0;
		loadAr >> destCount;

		CLine** pDestLines = new CLine*[destCount];
		for (std::size_t i = 0; i < destCount; ++i)
			loadAr >> pDestLines[i];

		for (std::size_t i = 0; i < destCount; ++i) {
			delete pDestLines[i];
			pDestLines[i] = nullptr;
		}
	}

	for (std::size_t i = 0; i < COUNT; ++i) {
		delete pLines[i];
		pLines[i] = nullptr;
	}

}

IMPLEMENT_SERIAL(CLine, CObject, 1)

void CLine::Serialize(CArchive& ar) {
	CObject::Serialize(ar);
	if (ar.IsStoring())
		ar << m_ptFrom << m_ptTo;
	else
		ar >> m_ptFrom >> m_ptTo;
}
