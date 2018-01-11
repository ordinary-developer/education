#include "stdafx.h"

#include "CoCarClassFactory.h"
#include "CoCar.h"

extern ULONG g_lockCount;
extern ULONG g_objCount;

CoCarClassFactory::CoCarClassFactory()
{
	m_refCount = 0;
	g_objCount++;
}

CoCarClassFactory::~CoCarClassFactory()
{
	g_objCount--;
}

// IUnknown
STDMETHODIMP_(ULONG) CoCarClassFactory::AddRef()
{
	return ++m_refCount;
}

STDMETHODIMP_(ULONG) CoCarClassFactory::Release()
{
	if (0 == --m_refCount)
	{
		delete this;
		return 0;
	}
	return m_refCount;
}

STDMETHODIMP CoCarClassFactory::QueryInterface(REFIID riid, void** ppv)
{
	if (riid == IID_IUnknown)
	{
		*ppv = (IUnknown*)this;
	}
	else if(riid == IID_IClassFactory)
	{
		*ppv = (IClassFactory*)this;
	}
	else
	{
		*ppv = NULL;
		return E_NOINTERFACE;
	}
	((IUnknown*)(*ppv))->AddRef();
	return S_OK;
}

// IClasFactory
STDMETHODIMP CoCarClassFactory::CreateInstance(LPUNKNOWN pUnkOuter,
											   REFIID riid,
											   void** ppv)
{
	if (NULL != pUnkOuter)
		return CLASS_E_NOAGGREGATION;
	CoCar* pCarObj = NULL;
	HRESULT hr;
	pCarObj = new CoCar();
	hr = pCarObj->QueryInterface(riid, ppv);
	if (FAILED(hr))
		delete pCarObj;
	return hr;
}

STDMETHODIMP CoCarClassFactory::LockServer(BOOL fLock)
{
	if (fLock)
		++g_lockCount;
	else
		--g_lockCount;
	return S_OK;	
}