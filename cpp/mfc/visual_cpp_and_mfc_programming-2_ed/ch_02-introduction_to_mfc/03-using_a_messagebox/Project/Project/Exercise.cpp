#include <afxwin.h>

class CExerciseApp : public CWinApp {
public:
	BOOL InitInstance();
};

CExerciseApp theApp;

BOOL CExerciseApp::InitInstance() {
	CWnd* msg = new CWnd;
	int answer = msg->MessageBox(L"The credentials you entered are not in our records\n"
								 L"What do you want to do? Click:\n"
								 L"Yes\tto contact Human Resources\n"
								 L"No\tto close the application\n"
								 L"Cancel\tto try again\n",
								 L"Failed Logon Attempt",
								 MB_YESNOCANCEL | MB_ICONQUESTION);

	if (IDYES == answer)
		::MessageBox(nullptr, L"IDYES", L"test", 0);

	if (IDNO == answer)
		::MessageBox(nullptr, L"IDNO", L"test", 0);

	if (IDCANCEL == answer)
		::MessageBox(nullptr, L"IDCANCEL", L"test", 0);

	return TRUE;
}