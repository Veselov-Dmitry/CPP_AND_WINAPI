// VeselovProp.h : Declaration of the CVeselovProp


#pragma once
#include "resource.h"       // main symbols


#include "Function_i.h"

using namespace ATL;

// CVeselovProp

class ATL_NO_VTABLE CVeselovProp :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CVeselovProp, &CLSID_VeselovProp>,
	public IPropertyPageImpl<CVeselovProp>,
	public ATL::CDialogImpl<CVeselovProp>
{
public:
	CVeselovProp()
	{
		m_dwTitleID = IDS_TITLEROMASHPROP;
		m_dwHelpFileID = IDS_HELPFILEROMASHPROP;
		m_dwDocStringID = IDS_DOCSTRINGROMASHPROP;
	}

	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

	enum {IDD = IDD_ROMASHPROP};

DECLARE_REGISTRY_RESOURCEID(IDR_ROMASHPROP)


BEGIN_COM_MAP(CVeselovProp)
	COM_INTERFACE_ENTRY(IPropertyPage)
END_COM_MAP()

BEGIN_MSG_MAP(CVeselovProp)
	CHAIN_MSG_MAP(IPropertyPageImpl<CVeselovProp>)
END_MSG_MAP()

// Handler prototypes:
//  LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
//  LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
//  LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);

	STDMETHOD(Apply)(void)
	{
		ATLTRACE(_T("CVeselovProp::Apply\n"));
		for (UINT i = 0; i < m_nObjects; i++)
		{
			// Do something interesting here
			// ICircCtl* pCirc;
			// m_ppUnk[i]->QueryInterface(IID_ICircCtl, (void**)&pCirc);
			// pCirc->put_Caption(CComBSTR("something special"));
			// pCirc->Release();
		}
		m_bDirty = FALSE;
		return S_OK;
	}
};


OBJECT_ENTRY_AUTO(__uuidof(VeselovProp), CVeselovProp)
