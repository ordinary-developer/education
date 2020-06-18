// CarInProcServer.cpp: определяет экспортированные функции для приложения DLL.
//

#include "stdafx.h"

#include <windows.h>

#include "CoCarClassFactory.h"
#include "iid.h"

ULONG g_lockCount = 0;
ULONG g_objCount = 0;

STDAPI DllCanUnloadNow()
{
	if (0 == g_lockCount && 0 == g_objCount)
		return S_OK;
	else
		return S_FALSE;
}

STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, void** ppv)
{
	CoCarClassFactory* pCFact = NULL;
	if (rclsid != CLSID_CoCar)
	{
		MessageBox(nullptr, L"class not found", L"test", 0);
		return CLASS_E_CLASSNOTAVAILABLE;
	}
	pCFact = new CoCarClassFactory;
	HRESULT hr = pCFact->QueryInterface(riid, ppv);
	if (FAILED(hr))
		delete pCFact;
	return S_OK;
}