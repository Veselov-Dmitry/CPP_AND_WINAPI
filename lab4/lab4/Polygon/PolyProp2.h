// PolyProp2.h : Declaration of the CPolyProp2


#pragma once
#include "resource.h"       // main symbols


#include "Polygon_i.h"

using namespace ATL;

// CPolyProp2

class ATL_NO_VTABLE CPolyProp2 :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CPolyProp2, &CLSID_PolyProp2>,
	public IPropertyPageImpl<CPolyProp2>,
	public ATL::CDialogImpl<CPolyProp2>
{
public:
	CPolyProp2()
	{
		m_dwTitleID = IDS_TITLEPOLYPROP2;
		m_dwHelpFileID = IDS_HELPFILEPOLYPROP2;
		m_dwDocStringID = IDS_DOCSTRINGPOLYPROP2;
	}

	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

	enum {IDD = IDD_POLYPROP2};

DECLARE_REGISTRY_RESOURCEID(IDR_POLYPROP2)


BEGIN_COM_MAP(CPolyProp2)
	COM_INTERFACE_ENTRY(IPropertyPage)
END_COM_MAP()

BEGIN_MSG_MAP(CPolyProp2)
	CHAIN_MSG_MAP(IPropertyPageImpl<CPolyProp2>)
END_MSG_MAP()

// Handler prototypes:
//  LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
//  LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
//  LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);

	STDMETHOD(Apply)(void)
	{
		ATLTRACE(_T("CPolyProp2::Apply\n"));
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


OBJECT_ENTRY_AUTO(__uuidof(PolyProp2), CPolyProp2)
