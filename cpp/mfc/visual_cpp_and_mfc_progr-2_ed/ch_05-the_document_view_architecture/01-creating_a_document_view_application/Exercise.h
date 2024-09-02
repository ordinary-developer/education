#pragma once
#include <afxext.h> // For CEditView
#include "resource.h"
class CExerciseApp : public CWinApp
{
	BOOL InitInstance();
	DECLARE_MESSAGE_MAP()
};

class CMainFrame : public CFrameWnd
{
	DECLARE_DYNCREATE(CMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()
};

class CExerciseDoc : public CDocument
{
	DECLARE_DYNCREATE(CExerciseDoc)
	DECLARE_MESSAGE_MAP()
};

class CExerciseView : public CEditView
{
	DECLARE_DYNCREATE(CExerciseView)
	DECLARE_MESSAGE_MAP()
};
