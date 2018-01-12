

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Fri Jan 12 17:13:14 2018
 */
/* Compiler settings for CarInProcServer.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0603 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __CarInProcServer_h_h__
#define __CarInProcServer_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IStats_FWD_DEFINED__
#define __IStats_FWD_DEFINED__
typedef interface IStats IStats;

#endif 	/* __IStats_FWD_DEFINED__ */


#ifndef __IEngine_FWD_DEFINED__
#define __IEngine_FWD_DEFINED__
typedef interface IEngine IEngine;

#endif 	/* __IEngine_FWD_DEFINED__ */


#ifndef __ICreateCar_FWD_DEFINED__
#define __ICreateCar_FWD_DEFINED__
typedef interface ICreateCar ICreateCar;

#endif 	/* __ICreateCar_FWD_DEFINED__ */


#ifndef __CoCar_FWD_DEFINED__
#define __CoCar_FWD_DEFINED__

#ifdef __cplusplus
typedef class CoCar CoCar;
#else
typedef struct CoCar CoCar;
#endif /* __cplusplus */

#endif 	/* __CoCar_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IStats_INTERFACE_DEFINED__
#define __IStats_INTERFACE_DEFINED__

/* interface IStats */
/* [helpstring][uuid][object] */ 


EXTERN_C const IID IID_IStats;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A533DA31-D372-11d2-B8CF-0020781238D4")
    IStats : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE DisplayStats( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPetName( 
            /* [retval][out] */ BSTR *petName) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IStatsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IStats * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IStats * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IStats * This);
        
        HRESULT ( STDMETHODCALLTYPE *DisplayStats )( 
            IStats * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetPetName )( 
            IStats * This,
            /* [retval][out] */ BSTR *petName);
        
        END_INTERFACE
    } IStatsVtbl;

    interface IStats
    {
        CONST_VTBL struct IStatsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IStats_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IStats_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IStats_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IStats_DisplayStats(This)	\
    ( (This)->lpVtbl -> DisplayStats(This) ) 

#define IStats_GetPetName(This,petName)	\
    ( (This)->lpVtbl -> GetPetName(This,petName) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IStats_INTERFACE_DEFINED__ */


#ifndef __IEngine_INTERFACE_DEFINED__
#define __IEngine_INTERFACE_DEFINED__

/* interface IEngine */
/* [helpstring][uuid][object] */ 


EXTERN_C const IID IID_IEngine;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A533DA30-D372-11d2-B8CF-0020781238D4")
    IEngine : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SpeedUp( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMaxSpeed( 
            /* [retval][out] */ int *maxSpeed) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCurSpeed( 
            /* [retval][out] */ int *curSpeed) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IEngineVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IEngine * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IEngine * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IEngine * This);
        
        HRESULT ( STDMETHODCALLTYPE *SpeedUp )( 
            IEngine * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetMaxSpeed )( 
            IEngine * This,
            /* [retval][out] */ int *maxSpeed);
        
        HRESULT ( STDMETHODCALLTYPE *GetCurSpeed )( 
            IEngine * This,
            /* [retval][out] */ int *curSpeed);
        
        END_INTERFACE
    } IEngineVtbl;

    interface IEngine
    {
        CONST_VTBL struct IEngineVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEngine_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IEngine_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IEngine_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IEngine_SpeedUp(This)	\
    ( (This)->lpVtbl -> SpeedUp(This) ) 

#define IEngine_GetMaxSpeed(This,maxSpeed)	\
    ( (This)->lpVtbl -> GetMaxSpeed(This,maxSpeed) ) 

#define IEngine_GetCurSpeed(This,curSpeed)	\
    ( (This)->lpVtbl -> GetCurSpeed(This,curSpeed) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IEngine_INTERFACE_DEFINED__ */


#ifndef __ICreateCar_INTERFACE_DEFINED__
#define __ICreateCar_INTERFACE_DEFINED__

/* interface ICreateCar */
/* [helpstring][uuid][object] */ 


EXTERN_C const IID IID_ICreateCar;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A533DA32-D372-11d2-B8CF-0020781238D4")
    ICreateCar : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetPetName( 
            /* [in] */ BSTR petName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMaxSpeed( 
            /* [in] */ int maxSp) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICreateCarVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICreateCar * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICreateCar * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICreateCar * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetPetName )( 
            ICreateCar * This,
            /* [in] */ BSTR petName);
        
        HRESULT ( STDMETHODCALLTYPE *SetMaxSpeed )( 
            ICreateCar * This,
            /* [in] */ int maxSp);
        
        END_INTERFACE
    } ICreateCarVtbl;

    interface ICreateCar
    {
        CONST_VTBL struct ICreateCarVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICreateCar_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICreateCar_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICreateCar_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICreateCar_SetPetName(This,petName)	\
    ( (This)->lpVtbl -> SetPetName(This,petName) ) 

#define ICreateCar_SetMaxSpeed(This,maxSp)	\
    ( (This)->lpVtbl -> SetMaxSpeed(This,maxSp) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICreateCar_INTERFACE_DEFINED__ */



#ifndef __CarInProcServer_LIBRARY_DEFINED__
#define __CarInProcServer_LIBRARY_DEFINED__

/* library CarInProcServer */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_CarInProcServer;

EXTERN_C const CLSID CLSID_CoCar;

#ifdef __cplusplus

class DECLSPEC_UUID("7AD2D539-EE35-11d2-B8DE-0020781238D4")
CoCar;
#endif
#endif /* __CarInProcServer_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


