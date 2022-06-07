
// Project.h : главный файл заголовка для приложения Project
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CProjectApp:
// О реализации данного класса см. Project.cpp
//

class CProjectApp : public CWinApp
{
public:
	CProjectApp();


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CProjectApp theApp;
