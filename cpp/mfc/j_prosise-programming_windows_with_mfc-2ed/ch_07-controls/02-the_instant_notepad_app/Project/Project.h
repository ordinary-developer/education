
// Project.h : ������� ���� ��������� ��� ���������� Project
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"       // �������� �������


// CProjectApp:
// � ���������� ������� ������ ��. Project.cpp
//

class CProjectApp : public CWinApp
{
public:
	CProjectApp();


// ���������������
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ����������

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CProjectApp theApp;
