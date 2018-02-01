
// Project.h : main header file for the Project application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CProjectApp:
// See Project.cpp for the implementation of this class
//

class CProjectApp : public CWinApp
{
public:
	CProjectApp();


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CProjectApp theApp;
