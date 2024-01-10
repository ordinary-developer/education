#pragma once

#include "interfaces.h"
#include "iid.h"

class CoCar : public IEngine, public ICreateCar, public IStats
{
public:
	CoCar();
	virtual ~CoCar();

	// IUnknown
	STDMETHODIMP QueryInterface(REFIID riid, void** pIFace);
	STDMETHODIMP_(ULONG)AddRef();
	STDMETHODIMP_(ULONG)Release();

	// IEngine
	STDMETHODIMP SpeedUp();
	STDMETHODIMP GetMaxSpeed(int* maxSpeed);
	STDMETHODIMP GetCurSpeed(int* curSpeed);

	// IStats 
	STDMETHODIMP DisplayStats();
	STDMETHODIMP GetPetName(BSTR* petName);

	// ICreateCar
	STDMETHODIMP SetPetName(BSTR petName);
	STDMETHODIMP SetMaxSpeed(int maxSp);

private:
	BSTR m_petName;
	int m_maxSpeed;
	int m_currSpeed;

	ULONG m_refCount;

	static const int MAX_SPEED = 200;
	static const int MAX_LENGTH = 1000;
};