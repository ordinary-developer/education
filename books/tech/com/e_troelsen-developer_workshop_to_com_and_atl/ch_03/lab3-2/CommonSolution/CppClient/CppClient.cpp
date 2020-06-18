// CppClient.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include "iid.h"
#include "interfaces.h"


int main()
{
	CoInitialize(NULL);
	HRESULT hr;
	IClassFactory* pCF = NULL;
	ICreateCar* pICreateCar = NULL;
	IStats* pStats = NULL;
	IEngine* pEngine = NULL;
	std::cout << "**************************" << std::endl;
	std::cout << "The amazing CoCar Client" << std::endl;
	std::cout << "**************************" << std::endl;

	hr = CoGetClassObject(CLSID_CoCar, CLSCTX_INPROC_SERVER,
						  NULL, IID_IClassFactory, (void**)&pCF);
	hr = pCF->CreateInstance(NULL, IID_ICreateCar, (void**)&pICreateCar);
	pCF->Release();
	if (SUCCEEDED(hr)) {
		pICreateCar->SetMaxSpeed(30);
		BSTR petName = SysAllocString(L"Shazzam!");
		pICreateCar->SetPetName(petName);
		SysFreeString(petName);
		hr = pICreateCar->QueryInterface(IID_IStats, (void**)&pStats);
		pICreateCar->Release();
		std::cout << "bam" << std::endl;
	}

	if (SUCCEEDED(hr)) {
		pStats->DisplayStats();
		hr = pStats->QueryInterface(IID_IEngine, (void**)&pEngine);
	}

	if(SUCCEEDED(hr))
     {
          int curSp = 0;
          int maxSp = 0;          
          pEngine->GetMaxSpeed(&maxSp);
          do{
               pEngine->SpeedUp();
               pEngine->GetCurSpeed(&curSp);
               std::cout << "Speed is: " << curSp << std::endl;
          }while(curSp <= maxSp);
          // Convert BSTR to char array.
          char buff[80];
          BSTR bstr;
          pStats->GetPetName(&bstr);
          WideCharToMultiByte(CP_ACP, NULL, bstr, -1, buff, 80, NULL, NULL);
          std::cout << buff << " has blown up! Lead Foot!" << std::endl << std::endl;
          // Final clean up.
          SysFreeString(bstr);
          if(pEngine)
               pEngine->Release();
          if(pStats)
               pStats->Release();
     }
     CoUninitialize();
    return 0;
}

