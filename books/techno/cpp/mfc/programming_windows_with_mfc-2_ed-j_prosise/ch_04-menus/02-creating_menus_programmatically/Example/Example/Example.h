
// Example.h : main header file for the Example application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CExampleApp:
// See Example.cpp for the implementation of this class
//

class CExampleApp : public CWinApp
{
public:
	CExampleApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CExampleApp theApp;
