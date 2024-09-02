#include <afxwin.h>
#include "Exercise.h"

BEGIN_MESSAGE_MAP(CExerciseApp, CWinApp)
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
	ON_COMMAND(ID_FILE_PRINT_SETUP, CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()

BOOL CExerciseApp::InitInstance()
{
#ifdef _AFXDLL
	Enable3dControls();
#else
	Enable3dControlsStatic();
#endif

	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(IDR_MAINFRAME,
										  RUNTIME_CLASS(CExerciseDoc),
										  RUNTIME_CLASS(CMainFrame),
										  RUNTIME_CLASS(CExerciseView));
	AddDocTemplate(pDocTemplate);

	// Dispatch commands specified on the command line
	CCommandLineInfo cmdInfo;
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// The one and only window has been initialized, so show and update it.
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	return TRUE;

}

// -- Frame Map -- //
IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)
BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
ON_WM_CREATE()
END_MESSAGE_MAP()

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	// Call the base class to create the window
	if( CFrameWnd::OnCreate(lpCreateStruct) == 0)
		return 0;
	return -1;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	cs.style &= ~(WS_MAXIMIZEBOX | WS_MINIMIZEBOX);
	cs.cx = 450;
	cs.cy = 350;

	return CFrameWnd::PreCreateWindow(cs);
}

// -- Document Map -- //
IMPLEMENT_DYNCREATE(CExerciseDoc, CDocument)
BEGIN_MESSAGE_MAP(CExerciseDoc, CDocument)
END_MESSAGE_MAP()
BOOL CExerciseDoc::OnNewDocument()
{
	return CDocument::OnNewDocument();
}

// -- View Map --
IMPLEMENT_DYNCREATE(CExerciseView, CEditView)
BEGIN_MESSAGE_MAP(CExerciseView, CEditView)
END_MESSAGE_MAP()


CExerciseApp theApp;