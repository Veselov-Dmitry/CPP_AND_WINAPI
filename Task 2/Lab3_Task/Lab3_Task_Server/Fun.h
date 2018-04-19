// Fun.h : Declaration of the CFun

#pragma once
#include "resource.h"       // main symbols



#include "Lab3_Task_Server_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;


// CFun

class ATL_NO_VTABLE CFun :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CFun, &CLSID_CoFun>,
	public IDispatchImpl<IFun, &IID_IFun, &LIBID_Lab3_Task_ServerLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CFun()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_FUN)


BEGIN_COM_MAP(CFun)
	COM_INTERFACE_ENTRY(IFun)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:	
	STDMETHOD(Fun121)(DOUBLE op1, DOUBLE op2, LONG* pResult);	
	STDMETHOD(Fun123)(DOUBLE op1, DOUBLE* pResult);
	STDMETHOD(Fun122)(LONG op1, LONG op2, LONG op3, FLOAT* pResult);
};

OBJECT_ENTRY_AUTO(__uuidof(CoFun), CFun)

