// Project.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include "interfaces.h"
#include "CoCar.h"

#include <iostream>

HRESULT CarFactory(void** pIFace)
{
	HRESULT hr;
	LPUNKNOWN pUnk = NULL;
	CoCar *pCar = new CoCar();
	hr = pCar->QueryInterface(IID_IUnknown, (void**)&pUnk);
	if (SUCCEEDED(hr))
	{
		*pIFace = pUnk;
		return S_OK;
	}
	else
	{
		delete pCar;
		return E_FAIL;
	}

	return S_OK;
}

int _tmain(int argc, _TCHAR* argv[])
{
	// step 0
	IUnknown* pUnk;
	HRESULT hr = CarFactory((void**)&pUnk);

	// step 1
	ICreateCar* pICreateCar;
	pUnk->QueryInterface(IID_ICreateCar, (void**)&pICreateCar);
	pICreateCar->SetMaxSpeed(30);
	BSTR name = SysAllocString(OLESTR("Bertha"));
	pICreateCar->SetPetName(name);
	SysFreeString(name);

	// step 2
	IStats* pIStats;
	pUnk->QueryInterface(IID_IStats, (void**)&pIStats);
	pIStats->DisplayStats();

	// step 3
	IEngine* pIEngine;
	int curSp = 0;
	int maxSp = 0;
	pUnk->QueryInterface(IID_IEngine, (void**)&pIEngine);
	pIEngine->GetMaxSpeed(&maxSp);
	do
	{
		pIEngine->SpeedUp();
		pIEngine->GetCurSpeed(&curSp);
		std::cout << "Speed is: " << curSp << std::endl;
	} while (curSp <= maxSp);
	char buff[100];
	BSTR bstr;
	pIStats->GetPetName(&bstr);
	wcstombs(buff, bstr, 100);
	std::cout << buff << " has blown up! Lead Foot!" << std::endl << std::endl;
	SysFreeString(bstr);

	// releasing
	if (pUnk)
		pUnk->Release();
	if (pIEngine)
		pIEngine->Release();
	if (pIStats)
		pIStats->Release();
	if (pICreateCar)
		pICreateCar->Release();

	return 0;
}

