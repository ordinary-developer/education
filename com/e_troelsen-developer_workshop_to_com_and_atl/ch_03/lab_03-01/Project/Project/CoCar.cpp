#include "stdafx.h"

#include "CoCar.h"

CoCar::CoCar()
	: m_refCount(0), m_currSpeed(0), m_maxSpeed(0)
{
	m_petName = SysAllocString(L"Default Pet Name");
}

CoCar::~CoCar() 
{
	if (m_petName)
		SysFreeString(m_petName);
}

// IUnknown
STDMETHODIMP_(ULONG) CoCar::AddRef()
{
	return ++m_refCount;
}

STDMETHODIMP_(ULONG) CoCar::Release()
{
	if (0 == --m_refCount)
	{
		delete this;
		return 0;
	}
	else
		return m_refCount;
}

STDMETHODIMP CoCar::QueryInterface(REFIID riid, void** pIFace)
{
	if (riid == IID_IUnknown)
	{
		*pIFace = (IUnknown*)(IEngine*)this;
	}
	else if(riid == IID_IEngine)
	{
		*pIFace = (IEngine*)this;
	}
	else if (riid == IID_IStats)
	{
		*pIFace = (IStats*)this;
	}
	else if(riid == IID_ICreateCar)
	{
		*pIFace = (ICreateCar*)this;
	}
	else
	{
		*pIFace = NULL;
		return E_NOINTERFACE;
	}
	((IUnknown*)(*pIFace))->AddRef();
	return S_OK;
}

// IEngine
STDMETHODIMP CoCar::SpeedUp()
{
	m_currSpeed += 10;
	return S_OK;
}

STDMETHODIMP CoCar::GetMaxSpeed(int* maxSpeed)
{
	*maxSpeed = m_maxSpeed;
	return S_OK;
}

STDMETHODIMP CoCar::GetCurSpeed(int* curSpeed)
{
	*curSpeed = m_currSpeed;
	return S_OK;
}

// IStats
STDMETHODIMP CoCar::DisplayStats()
{ 
	char buff[MAX_LENGTH];
	::WideCharToMultiByte(CP_ACP, NULL, m_petName, -1, buff, MAX_LENGTH, NULL, NULL);
	MessageBoxA(NULL, buff, "Pet Name", MB_OK | MB_SETFOREGROUND);
	memset(buff, 0, sizeof(buff));
	sprintf(buff, "%d", m_maxSpeed);
	MessageBoxA(NULL, buff, "Max Speed", MB_OK | MB_SETFOREGROUND);
	return S_OK;
}

STDMETHODIMP CoCar::GetPetName(BSTR* petName)
{
	*petName = SysAllocString(m_petName);
	return S_OK;
}

// ICreateCar
STDMETHODIMP CoCar::SetPetName(BSTR petName)
{
	SysReAllocString(&m_petName, petName);
	return S_OK;
}

STDMETHODIMP CoCar::SetMaxSpeed(int maxSp)
{
	if (maxSp < MAX_SPEED)
		m_maxSpeed = maxSp;
	return S_OK;
}