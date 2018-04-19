

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Thu May 18 23:03:25 2017
 */
/* Compiler settings for Polygon.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 7.00.0555 
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

MIDL_DEFINE_GUID(IID, IID_IPolyCtl,0x84244CCB,0x7677,0x4CB3,0x98,0xC1,0x77,0x5F,0x11,0x11,0x4C,0x48);


MIDL_DEFINE_GUID(IID, LIBID_PolygonLib,0xCF541310,0x7676,0x409C,0xA8,0xCE,0x3C,0x64,0x91,0xBA,0x97,0x83);


MIDL_DEFINE_GUID(IID, DIID__IPolyCtlEvents,0x2BB72C1E,0x8F92,0x448C,0x9B,0x25,0x92,0xC2,0x47,0x01,0xA4,0x6E);


MIDL_DEFINE_GUID(CLSID, CLSID_CoPolyCtl,0x55AB641A,0xC129,0x4D67,0xB0,0xDC,0xC0,0xDD,0xF4,0xFB,0x94,0x9A);


MIDL_DEFINE_GUID(CLSID, CLSID_PolyProp,0xD3193E59,0xD6F1,0x4646,0x9B,0x99,0x8F,0x43,0x00,0xB7,0xE1,0xA2);


MIDL_DEFINE_GUID(CLSID, CLSID_PolyProp2,0xB108880F,0x08CF,0x4237,0xB2,0x38,0x6F,0x5D,0x70,0x2E,0x02,0xD9);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



