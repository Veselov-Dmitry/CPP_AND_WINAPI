

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Thu May 18 18:40:07 2017
 */
/* Compiler settings for Function.idl:
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

MIDL_DEFINE_GUID(IID, IID_IVeselov,0x46E3DA6B,0xAE15,0x443E,0x83,0x1D,0x3F,0xC3,0xF1,0x7C,0x61,0x2D);


MIDL_DEFINE_GUID(IID, LIBID_FunctionLib,0x684A8D4C,0x065A,0x490C,0xB5,0x30,0x20,0x44,0x6A,0x72,0x85,0xCE);


MIDL_DEFINE_GUID(IID, DIID__IVeselovEvents,0x73221A45,0x76F7,0x430D,0xAC,0xAE,0xBE,0x27,0x7C,0x11,0x02,0xCE);


MIDL_DEFINE_GUID(CLSID, CLSID_CoVeselov,0x1B565837,0x2CE2,0x4C59,0x90,0x8F,0x30,0xE8,0x78,0xC8,0x6F,0x24);


MIDL_DEFINE_GUID(CLSID, CLSID_VeselovProp,0xD938932E,0xEA02,0x4D56,0xA5,0x44,0x05,0x05,0xDF,0x1E,0xC5,0x8C);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



