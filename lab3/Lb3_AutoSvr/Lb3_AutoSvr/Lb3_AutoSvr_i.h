

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Thu May 18 14:08:16 2017
 */
/* Compiler settings for Lb3_AutoSvr.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 7.00.0555 
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

#ifndef __Lb3_AutoSvr_i_h__
#define __Lb3_AutoSvr_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IMyMath_FWD_DEFINED__
#define __IMyMath_FWD_DEFINED__
typedef interface IMyMath IMyMath;
#endif 	/* __IMyMath_FWD_DEFINED__ */


#ifndef __CoMyMath_FWD_DEFINED__
#define __CoMyMath_FWD_DEFINED__

#ifdef __cplusplus
typedef class CoMyMath CoMyMath;
#else
typedef struct CoMyMath CoMyMath;
#endif /* __cplusplus */

#endif 	/* __CoMyMath_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IMyMath_INTERFACE_DEFINED__
#define __IMyMath_INTERFACE_DEFINED__

/* interface IMyMath */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IMyMath;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F1692F96-B261-490B-8B9B-4C8A3E9E7C34")
    IMyMath : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ LONG op1,
            /* [in] */ LONG op2,
            /* [retval][out] */ LONG *pResult) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Subtract( 
            /* [in] */ LONG op1,
            /* [in] */ LONG op2,
            /* [retval][out] */ LONG *pResult) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Multiply( 
            /* [in] */ LONG op1,
            /* [in] */ LONG op2,
            /* [retval][out] */ LONG *pResult) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Divide( 
            /* [in] */ LONG op1,
            /* [in] */ LONG op2,
            /* [retval][out] */ LONG *pResult) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMyMathVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMyMath * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMyMath * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMyMath * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMyMath * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMyMath * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMyMath * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMyMath * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            IMyMath * This,
            /* [in] */ LONG op1,
            /* [in] */ LONG op2,
            /* [retval][out] */ LONG *pResult);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Subtract )( 
            IMyMath * This,
            /* [in] */ LONG op1,
            /* [in] */ LONG op2,
            /* [retval][out] */ LONG *pResult);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Multiply )( 
            IMyMath * This,
            /* [in] */ LONG op1,
            /* [in] */ LONG op2,
            /* [retval][out] */ LONG *pResult);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Divide )( 
            IMyMath * This,
            /* [in] */ LONG op1,
            /* [in] */ LONG op2,
            /* [retval][out] */ LONG *pResult);
        
        END_INTERFACE
    } IMyMathVtbl;

    interface IMyMath
    {
        CONST_VTBL struct IMyMathVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMyMath_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMyMath_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMyMath_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMyMath_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMyMath_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMyMath_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMyMath_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMyMath_Add(This,op1,op2,pResult)	\
    ( (This)->lpVtbl -> Add(This,op1,op2,pResult) ) 

#define IMyMath_Subtract(This,op1,op2,pResult)	\
    ( (This)->lpVtbl -> Subtract(This,op1,op2,pResult) ) 

#define IMyMath_Multiply(This,op1,op2,pResult)	\
    ( (This)->lpVtbl -> Multiply(This,op1,op2,pResult) ) 

#define IMyMath_Divide(This,op1,op2,pResult)	\
    ( (This)->lpVtbl -> Divide(This,op1,op2,pResult) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMyMath_INTERFACE_DEFINED__ */



#ifndef __Lb3_AutoSvrLib_LIBRARY_DEFINED__
#define __Lb3_AutoSvrLib_LIBRARY_DEFINED__

/* library Lb3_AutoSvrLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_Lb3_AutoSvrLib;

EXTERN_C const CLSID CLSID_CoMyMath;

#ifdef __cplusplus

class DECLSPEC_UUID("03F51E41-BB88-4C61-91F8-D602DCD2D439")
CoMyMath;
#endif
#endif /* __Lb3_AutoSvrLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


