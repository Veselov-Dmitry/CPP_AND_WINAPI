// Veselov.h : Declaration of the CVeselov
#pragma once
#include "resource.h"       // main symbols
#include <atlctl.h>
#include <math.h>
#include "Function_i.h"
#include "_IVeselovEvents_CP.h"

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;



// CVeselov
class ATL_NO_VTABLE CVeselov :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CStockPropImpl<CVeselov, IVeselov>,
	public IOleControlImpl<CVeselov>,
	public IOleObjectImpl<CVeselov>,
	public IOleInPlaceActiveObjectImpl<CVeselov>,
	public IViewObjectExImpl<CVeselov>,
	public IOleInPlaceObjectWindowlessImpl<CVeselov>,
	public ISupportErrorInfo,
	public IConnectionPointContainerImpl<CVeselov>,
	public CProxy_IVeselovEvents<CVeselov>,
	public IQuickActivateImpl<CVeselov>,
#ifndef _WIN32_WCE
	public IDataObjectImpl<CVeselov>,
#endif
	public IProvideClassInfo2Impl<&CLSID_CoVeselov, &__uuidof(_IVeselovEvents), &LIBID_FunctionLib>,
	public CComCoClass<CVeselov, &CLSID_CoVeselov>,
	public CComControl<CVeselov>	
{
public:
	// цвет фона и линии графика
	OLE_COLOR m_clrBackColor, m_clrLineColor;
	// диапазон шкал осей х и у
	SHORT minX, maxX, minY, maxY;
	// флаги нажати€ клафишей мыши
	bool flagLButton, flagRButton, flagDBLButton, flagDBRButton;
	
	CVeselov()
	{
		// начальные значени€ оси
		minX = -2;
		maxX = 5;
		minY = -3;
		maxY = 6;
		// начальное значени€ цветов
		m_clrBackColor = RGB(0xFF,0,0xFF);
		m_clrLineColor = RGB(0,0,0);
		// начальные значение флагов
		flagLButton = false;
		flagRButton = false;
		flagDBLButton = false;
		flagDBRButton = false;
	}

DECLARE_OLEMISC_STATUS(OLEMISC_RECOMPOSEONRESIZE |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_INSIDEOUT |
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST
)

DECLARE_REGISTRY_RESOURCEID(IDR_ROMASH)


BEGIN_COM_MAP(CVeselov)
	COM_INTERFACE_ENTRY(IVeselov)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IViewObjectEx)
	COM_INTERFACE_ENTRY(IViewObject2)
	COM_INTERFACE_ENTRY(IViewObject)
	COM_INTERFACE_ENTRY(IOleInPlaceObjectWindowless)
	COM_INTERFACE_ENTRY(IOleInPlaceObject)
	COM_INTERFACE_ENTRY2(IOleWindow, IOleInPlaceObjectWindowless)
	COM_INTERFACE_ENTRY(IOleInPlaceActiveObject)
	COM_INTERFACE_ENTRY(IOleControl)
	COM_INTERFACE_ENTRY(IOleObject)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
	COM_INTERFACE_ENTRY(IQuickActivate)
#ifndef _WIN32_WCE
	COM_INTERFACE_ENTRY(IDataObject)
#endif
	COM_INTERFACE_ENTRY(IProvideClassInfo)
	COM_INTERFACE_ENTRY(IProvideClassInfo2)	
END_COM_MAP()

BEGIN_PROP_MAP(CVeselov)
	PROP_DATA_ENTRY("_cx", m_sizeExtent.cx, VT_UI4)
	PROP_DATA_ENTRY("_cy", m_sizeExtent.cy, VT_UI4)
#ifndef _WIN32_WCE
	PROP_ENTRY_TYPE("BackColor", DISPID_BACKCOLOR, CLSID_StockColorPage, VT_UI4)
#endif
	// Example entries
	// PROP_ENTRY_TYPE("Property Name", dispid, clsid, vtType)
	// PROP_PAGE(CLSID_StockColorPage)
END_PROP_MAP()

BEGIN_CONNECTION_POINT_MAP(CVeselov)
	CONNECTION_POINT_ENTRY(__uuidof(_IVeselovEvents))
END_CONNECTION_POINT_MAP()

BEGIN_MSG_MAP(CVeselov)
	CHAIN_MSG_MAP(CComControl<CVeselov>)
	DEFAULT_REFLECTION_HANDLER()
	MESSAGE_HANDLER(WM_LBUTTONDOWN, OnLButtonDown)
	MESSAGE_HANDLER(WM_RBUTTONDOWN, OnRButtonDown)
END_MSG_MAP()
// Handler prototypes:
//  LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
//  LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
//  LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);

// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid)
	{
		static const IID* const arr[] =
		{
			&IID_IVeselov,
		};

		for (int i=0; i<sizeof(arr)/sizeof(arr[0]); i++)
		{
			if (InlineIsEqualGUID(*arr[i], riid))
				return S_OK;
		}
		return S_FALSE;
	}

// IViewObjectEx
	DECLARE_VIEW_STATUS(VIEWSTATUS_SOLIDBKGND | VIEWSTATUS_OPAQUE)

// IVeselov
public:
	HRESULT OnDraw(ATL_DRAWINFO& di)
	{
		HBRUSH hBrush, hOldBrush;
		RECT& rc = *(RECT*)di.prcBounds;
		HDC hdc = di.hdcDraw;
		SHORT x,y, pointX, pointY;
		SHORT X,Y, negX, negY;
		SHORT delX, delY;
		SHORT a = -1, b = 4;
		COLORREF colorPen, colorBrush, colorPenLins = RGB(0,0,0);		
		HPEN hPenLine,hOldPen, hPenLinsOsi;
		// Set Clip region to the rectangle specified by di.prcBounds
		/*HRGN hRgnOld = NULL;
		if (GetClipRgn(hdc, hRgnOld) != 1)
			hRgnOld = NULL;
		bool bSelectOldRgn = false;*/
		

		//HRGN hRgnNew = CreateRectRgn(rc.left, rc.top, rc.right, rc.bottom);
		//m_clrBackColor = RGB(0xFF,0,0xFF);
		OleTranslateColor(m_clrBackColor,NULL,&colorBrush);	// цвет кисти
		OleTranslateColor(m_clrLineColor,NULL,&colorPen);	// цвет пера
		hBrush = CreateSolidBrush(colorBrush);				// создание кисти
		//hBrush = CreateSolidBrush(RGB(255,0,255));
		hOldBrush = (HBRUSH)SelectObject(hdc,hBrush);		// установка кисти
		/*if (hRgnNew != NULL)
		{
			bSelectOldRgn = (SelectClipRgn(di.hdcDraw, hRgnNew) != ERROR);
		}*/
		FillRect(hdc, &rc, hBrush);		// заполнение зааднего фона		
		X = abs(minX - maxX); // вы€сн€ю количество делений на шкале
		Y = abs(minY - maxY);
		delX = rc.right/X; // определение размера 1 делени€
		delY = rc.bottom/Y;
		negY = abs(delY*maxY);	// определение точек пересечени€ осей
		negX = abs(delX*minX);
		hPenLinsOsi = CreatePen(PS_SOLID,1,colorPenLins);	// создание пера дл€ оси
		hOldPen = (HPEN)SelectObject(hdc,hPenLinsOsi);		// установка пере дл€ оси
		MoveToEx(hdc, 0, negY, (LPPOINT) NULL); // перемещение курсора
		LineTo(hdc, rc.right, negY);			// рисование пр€мой
		MoveToEx(hdc,negX,0,(LPPOINT) NULL);
		LineTo(hdc,negX,rc.bottom);
		//MoveToEx(hdc,negX,negY,(LPPOINT) NULL);
		Ellipse(hdc,negX-2,negY-2,negX+2,negY+2);		// центр графика
		hPenLine = CreatePen(PS_SOLID,2,colorPen);		// создание пера
		if(flagLButton&&!flagRButton){			
			SelectObject(hdc,hPenLine);		//установка пера
			for(double i = a; i <= b; i++){
				y = pow(i,2) + 5* cos(i);		// функци€ по заданию	
				pointX = negX + i*delX;			// точки относительно оси графика
				pointY = negY - y*delY;			
				if(i == a)
					MoveToEx(hdc,pointX,pointY,(LPPOINT) NULL); // начальна€ точка
				else
					LineTo(hdc,pointX,pointY);		// прорисовка линии от точки до точки
				Ellipse(hdc,pointX-2,pointY-2,pointX+2,pointY+2);	// прорисовка узла
			}
		}
		if(flagDBLButton)			// генераци€ ошибки при повторном нажатии левой клавиши мыши
			return Error(_T("√рафик уже нарисован"));
		if(flagDBRButton)			// генераци€ ошибки при повторном нажатии левой клавиши мыши
			return Error(_T("√рафик уже удален"));
		/*SetTextAlign(hdc, TA_CENTER|TA_BASELINE);
		LPCTSTR pszText = _T("Veselov");
#ifndef _WIN32_WCE
		TextOut(di.hdcDraw,
			(rc.left + rc.right) / 2,
			(rc.top + rc.bottom) / 2,
			pszText,
			lstrlen(pszText));
#else
		ExtTextOut(di.hdcDraw,
			(rc.left + rc.right) / 2,
			(rc.top + rc.bottom) / 2,
			ETO_OPAQUE,
			NULL,
			pszText,
			ATL::lstrlen(pszText),
			NULL);
#endif*/

		SelectObject(hdc,hOldBrush);
		SelectObject(hdc,hOldPen);
		DeleteObject(hBrush);
		DeleteObject(hPenLine);
		DeleteObject(hPenLinsOsi);
		/*if (bSelectOldRgn)
			SelectClipRgn(di.hdcDraw, hRgnOld);*/

		return S_OK;
	}

	
	void OnBackColorChanged()
	{
		ATLTRACE(_T("OnBackColorChanged\n"));		
	}

	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}	
	STDMETHOD(get_MinX)(SHORT* pVal);
	STDMETHOD(put_MinX)(SHORT newVal);
	STDMETHOD(get_MaxX)(SHORT* pVal);
	STDMETHOD(put_MaxX)(SHORT newVal);
	STDMETHOD(get_MinY)(SHORT* pVal);
	STDMETHOD(put_MinY)(SHORT newVal);
	STDMETHOD(get_MaxY)(SHORT* pVal);
	STDMETHOD(put_MaxY)(SHORT newVal);
	STDMETHOD(get_LineColor)(OLE_COLOR* pVal);
	STDMETHOD(put_LineColor)(OLE_COLOR newVal);
	LRESULT OnLButtonDown(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
	LRESULT OnRButtonDown(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
};

OBJECT_ENTRY_AUTO(__uuidof(CoVeselov), CVeselov)
