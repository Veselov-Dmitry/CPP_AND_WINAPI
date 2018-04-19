

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


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

#ifndef __Function_i_h__
#define __Function_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IVeselov_FWD_DEFINED__
#define __IVeselov_FWD_DEFINED__
typedef interface IVeselov IVeselov;
#endif 	/* __IVeselov_FWD_DEFINED__ */


#ifndef ___IVeselovEvents_FWD_DEFINED__
#define ___IVeselovEvents_FWD_DEFINED__
typedef interface _IVeselovEvents _IVeselovEvents;
#endif 	/* ___IVeselovEvents_FWD_DEFINED__ */


#ifndef __CoVeselov_FWD_DEFINED__
#define __CoVeselov_FWD_DEFINED__

#ifdef __cplusplus
typedef class CoVeselov CoVeselov;
#else
typedef struct CoVeselov CoVeselov;
#endif /* __cplusplus */

#endif 	/* __CoVeselov_FWD_DEFINED__ */


#ifndef __VeselovProp_FWD_DEFINED__
#define __VeselovProp_FWD_DEFINED__

#ifdef __cplusplus
typedef class VeselovProp VeselovProp;
#else
typedef struct VeselovProp VeselovProp;
#endif /* __cplusplus */

#endif 	/* __VeselovProp_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IVeselov_INTERFACE_DEFINED__
#define __IVeselov_INTERFACE_DEFINED__

/* interface IVeselov */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IVeselov;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("46E3DA6B-AE15-443E-831D-3FC3F17C612D")
    IVeselov : public IDispatch
    {
    public:
        virtual /* [id][requestedit][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_BackColor( 
            /* [in] */ OLE_COLOR clr) = 0;
        
        virtual /* [id][requestedit][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_BackColor( 
            /* [retval][out] */ OLE_COLOR *pclr) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_MinX( 
            /* [retval][out] */ SHORT *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_MinX( 
            /* [in] */ SHORT newVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_MaxX( 
            /* [retval][out] */ SHORT *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_MaxX( 
            /* [in] */ SHORT newVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_MinY( 
            /* [retval][out] */ SHORT *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_MinY( 
            /* [in] */ SHORT newVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_MaxY( 
            /* [retval][out] */ SHORT *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_MaxY( 
            /* [in] */ SHORT newVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_LineColor( 
            /* [retval][out] */ OLE_COLOR *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_LineColor( 
            /* [in] */ OLE_COLOR newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVeselovVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVeselov * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVeselov * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVeselov * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IVeselov * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IVeselov * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IVeselov * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IVeselov * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id][requestedit][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BackColor )( 
            IVeselov * This,
            /* [in] */ OLE_COLOR clr);
        
        /* [id][requestedit][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BackColor )( 
            IVeselov * This,
            /* [retval][out] */ OLE_COLOR *pclr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MinX )( 
            IVeselov * This,
            /* [retval][out] */ SHORT *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MinX )( 
            IVeselov * This,
            /* [in] */ SHORT newVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MaxX )( 
            IVeselov * This,
            /* [retval][out] */ SHORT *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MaxX )( 
            IVeselov * This,
            /* [in] */ SHORT newVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MinY )( 
            IVeselov * This,
            /* [retval][out] */ SHORT *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MinY )( 
            IVeselov * This,
            /* [in] */ SHORT newVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MaxY )( 
            IVeselov * This,
            /* [retval][out] */ SHORT *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MaxY )( 
            IVeselov * This,
            /* [in] */ SHORT newVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LineColor )( 
            IVeselov * This,
            /* [retval][out] */ OLE_COLOR *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_LineColor )( 
            IVeselov * This,
            /* [in] */ OLE_COLOR newVal);
        
        END_INTERFACE
    } IVeselovVtbl;

    interface IVeselov
    {
        CONST_VTBL struct IVeselovVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVeselov_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IVeselov_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IVeselov_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IVeselov_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IVeselov_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IVeselov_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IVeselov_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IVeselov_put_BackColor(This,clr)	\
    ( (This)->lpVtbl -> put_BackColor(This,clr) ) 

#define IVeselov_get_BackColor(This,pclr)	\
    ( (This)->lpVtbl -> get_BackColor(This,pclr) ) 

#define IVeselov_get_MinX(This,pVal)	\
    ( (This)->lpVtbl -> get_MinX(This,pVal) ) 

#define IVeselov_put_MinX(This,newVal)	\
    ( (This)->lpVtbl -> put_MinX(This,newVal) ) 

#define IVeselov_get_MaxX(This,pVal)	\
    ( (This)->lpVtbl -> get_MaxX(This,pVal) ) 

#define IVeselov_put_MaxX(This,newVal)	\
    ( (This)->lpVtbl -> put_MaxX(This,newVal) ) 

#define IVeselov_get_MinY(This,pVal)	\
    ( (This)->lpVtbl -> get_MinY(This,pVal) ) 

#define IVeselov_put_MinY(This,newVal)	\
    ( (This)->lpVtbl -> put_MinY(This,newVal) ) 

#define IVeselov_get_MaxY(This,pVal)	\
    ( (This)->lpVtbl -> get_MaxY(This,pVal) ) 

#define IVeselov_put_MaxY(This,newVal)	\
    ( (This)->lpVtbl -> put_MaxY(This,newVal) ) 

#define IVeselov_get_LineColor(This,pVal)	\
    ( (This)->lpVtbl -> get_LineColor(This,pVal) ) 

#define IVeselov_put_LineColor(This,newVal)	\
    ( (This)->lpVtbl -> put_LineColor(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IVeselov_INTERFACE_DEFINED__ */



#ifndef __FunctionLib_LIBRARY_DEFINED__
#define __FunctionLib_LIBRARY_DEFINED__

/* library FunctionLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_FunctionLib;

#ifndef ___IVeselovEvents_DISPINTERFACE_DEFINED__
#define ___IVeselovEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IVeselovEvents */
/* [uuid] */ 


EXTERN_C const IID DIID__IVeselovEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("73221A45-76F7-430D-ACAE-BE277C1102CE")
    _IVeselovEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IVeselovEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IVeselovEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IVeselovEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IVeselovEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IVeselovEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IVeselovEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IVeselovEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IVeselovEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _IVeselovEventsVtbl;

    interface _IVeselovEvents
    {
        CONST_VTBL struct _IVeselovEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IVeselovEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IVeselovEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IVeselovEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IVeselovEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IVeselovEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IVeselovEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IVeselovEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IVeselovEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_CoVeselov;

#ifdef __cplusplus

class DECLSPEC_UUID("1B565837-2CE2-4C59-908F-30E878C86F24")
CoVeselov;
#endif

EXTERN_C const CLSID CLSID_VeselovProp;

#ifdef __cplusplus

class DECLSPEC_UUID("D938932E-EA02-4D56-A544-0505DF1EC58C")
VeselovProp;
#endif
#endif /* __FunctionLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


