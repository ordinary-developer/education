// CppClient.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <windows.h>
#include <iostream>

#include "E:\experiments\com\troelsen_4.1\CommonSolution\CarInProcServer\CarInProcServer.h"
//#include "E:\experiments\com\troelsen_4.1\CommonSolution\CarInProcServer\CarInProcServer_h.h"
#include "E:\experiments\com\troelsen_4.1\CommonSolution\CarInProcServer\CarInProcServer_i.c"
#import "E:\experiments\com\troelsen_4.1\CommonSolution\CarInProcServer\CarInProcServer.tlb"

using namespace std;
int main()
{

 CoInitialize(NULL);
     cout << "*********************************" << endl;
     cout << "The Amazing CoCar Import Client" << endl;
     cout << "*********************************" << endl;
     CarInProcServer::ICreateCarPtr iCCar(CLSID_CoCar);
     CarInProcServer::IEnginePtr iEng(iCCar);
     CarInProcServer::IStatsPtr iStats(iCCar);
     _bstr_t name = "Greased Lighting!";
     iCCar->SetPetName(name);
     iCCar->SetMaxSpeed(50);
     // Show our state.
     iStats->DisplayStats();
     int curSp = 0; int maxSp = 0;
     maxSp = iEng->GetMaxSpeed();
     do     // Zoom!
     {
          iEng->SpeedUp();
          curSp = iEng->GetCurSpeed();          // [out, retval]
          cout << "Speed is: " << curSp << endl;
     }while(curSp <= maxSp);
     // Blown up!
     _bstr_t bstrName;                         // No conversions!
     bstrName = iStats->GetPetName();          // [out, retval]
     cout << bstrName << " has blown up! Lead Foot!" << endl << endl;
     iCCar = NULL;
     iStats= NULL;
     iEng = NULL;
     CoUninitialize();
     return 0;
    return 0;
}

