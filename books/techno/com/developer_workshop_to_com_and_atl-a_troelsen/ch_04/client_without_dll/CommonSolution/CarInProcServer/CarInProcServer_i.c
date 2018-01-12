

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


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


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, IID_IStats,0xA533DA31,0xD372,0x11d2,0xB8,0xCF,0x00,0x20,0x78,0x12,0x38,0xD4);


MIDL_DEFINE_GUID(IID, IID_IEngine,0xA533DA30,0xD372,0x11d2,0xB8,0xCF,0x00,0x20,0x78,0x12,0x38,0xD4);


MIDL_DEFINE_GUID(IID, IID_ICreateCar,0xA533DA32,0xD372,0x11d2,0xB8,0xCF,0x00,0x20,0x78,0x12,0x38,0xD4);


MIDL_DEFINE_GUID(IID, LIBID_CarInProcServer,0x070F1346,0x7C75,0x4488,0xA3,0x06,0xD7,0xC8,0x50,0xAD,0x75,0x50);


MIDL_DEFINE_GUID(CLSID, CLSID_CoCar,0x7AD2D539,0xEE35,0x11d2,0xB8,0xDE,0x00,0x20,0x78,0x12,0x38,0xD4);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



