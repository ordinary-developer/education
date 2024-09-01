#pragma once 

#include <afxwin.h>


class CMyApp : public CWinApp {
public:
	virtual BOOL InitInstance() override;
};

class CMainWindow : public CFrameWnd {
public:
	CMainWindow();

	static int CALLBACK EnumFontFamProc(
		ENUMLOGFONT* lpelf, NEWTEXTMETRIC* llpntm, int nFontType, LPARAM lParam);

protected:
	virtual void PostNcDestroy();

	afx_msg int OnCreate(LPCREATESTRUCT lpcs);
	afx_msg void OnPushButtonClicked();
	afx_msg void OnCheckBoxClicked();
	afx_msg void OnSelChange();
	DECLARE_MESSAGE_MAP()

private:
	void FillListBox();

	int m_cxChar;
	int m_cyChar;

	CFont m_fontMain;
	CFont m_fontSample;

	CStatic m_wndLBTitle;
	CListBox m_wndListBox;
	CButton m_wndCheckBox;
	CButton m_wndGroupBox;
	CStatic m_wndSampleText;
	CButton m_wndPushButton;

private:
};



