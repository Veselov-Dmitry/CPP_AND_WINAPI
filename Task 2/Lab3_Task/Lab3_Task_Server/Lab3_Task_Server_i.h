

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Thu May 18 16:47:30 2017
 */
/* Compiler settings for Lab3_Task_Server.idl:
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

#ifndef __Lab3_Task_Server_i_h__
#define __Lab3_Task_Server_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IFun_FWD_DEFINED__
#define __IFun_FWD_DEFINED__
typedef interface IFun IFun;
#endif 	/* __IFun_FWD_DEFINED__ */


#ifndef __CoFun_FWD_DEFINED__
#define __CoFun_FWD_DEFINED__

#ifdef __cplusplus
typedef class CoFun CoFun;
#else
typedef struct CoFun CoFun;
#endif /* __cplusplus */

#endif 	/* __CoFun_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IFun_INTERFACE_DEFINED__
#define __IFun_INTERFACE_DEFINED__

/* interface IFun */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IFun;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("658590C3-6EC0-4E6D-880A-AA483EC6C16A")
    IFun : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Fun121( 
            /* [in] */ DOUBLE op1,
            /* [in] */ DOUBLE op2,
            /* [retval][out] */ LONG *pResult) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Fun123( 
            /* [in] */ DOUBLE op1,
            /* [retval][out] */ DOUBLE *pResult) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Fun122( 
            /* [in] */ LONG op1,
            /* [in] */ LONG op2,
            /* [in] */ LONG op3,
            /* [retval][out] */ FLOAT *pResult) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFunVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFun * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFun * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFun * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFun * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFun * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFun * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFun * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Fun121 )( 
            IFun * This,
            /* [in] */ DOUBLE op1,
            /* [in] */ DOUBLE op2,
            /* [retval][out] */ LONG *pResult);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Fun123 )( 
            IFun * This,
            /* [in] */ DOUBLE op1,
            /* [retval][out] */ DOUBLE *pResult);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Fun122 )( 
            IFun * This,
            /* [in] */ LONG op1,
            /* [in] */ LONG op2,
            /* [in] */ LONG op3,
            /* [retval][out] */ FLOAT *pResult);
        
        END_INTERFACE
    } IFunVtbl;

    interface IFun
    {
        CONST_VTBL struct IFunVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFun_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFun_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFun_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFun_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFun_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFun_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFun_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IFun_Fun121(This,op1,op2,pResult)	\
    ( (This)->lpVtbl -> Fun121(This,op1,op2,pResult) ) 

#define IFun_Fun123(This,op1,pResult)	\
    ( (This)->lpVtbl -> Fun123(This,op1,pResult) ) 

#define IFun_Fun122(This,op1,op2,op3,pResult)	\
    ( (This)->lpVtbl -> Fun122(This,op1,op2,op3,pResult) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFun_INTERFACE_DEFINED__ */



#ifndef __Lab3_Task_ServerLib_LIBRARY_DEFINED__
#define __Lab3_Task_ServerLib_LIBRARY_DEFINED__

/* library Lab3_Task_ServerLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_Lab3_Task_ServerLib;

EXTERN_C const CLSID CLSID_CoFun;

#ifdef __cplusplus

class DECLSPEC_UUID("A8810077-5619-4F23-A139-EB77D7182A65")
CoFun;
#endif
#endif /* __Lab3_Task_ServerLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


