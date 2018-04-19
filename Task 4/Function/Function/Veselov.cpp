// Veselov.cpp : Implementation of CVeselov
#include "stdafx.h"
#include "Veselov.h"


// CVeselov





STDMETHODIMP CVeselov::get_MinX(SHORT* pVal)
{
	// TODO: Add your implementation code here
	*pVal = minX;
	return S_OK;
}


STDMETHODIMP CVeselov::put_MinX(SHORT newVal)
{
	// TODO: Add your implementation code here
	minX = newVal;
	FireViewChange();
	return S_OK;
}


STDMETHODIMP CVeselov::get_MaxX(SHORT* pVal)
{
	// TODO: Add your implementation code here
	*pVal = maxX;
	return S_OK;
}


STDMETHODIMP CVeselov::put_MaxX(SHORT newVal)
{
	// TODO: Add your implementation code here
	maxX = newVal;
	FireViewChange();
	return S_OK;
}


STDMETHODIMP CVeselov::get_MinY(SHORT* pVal)
{
	// TODO: Add your implementation code here
	*pVal = minY;
	return S_OK;
}


STDMETHODIMP CVeselov::put_MinY(SHORT newVal)
{
	// TODO: Add your implementation code here
	minY = newVal;
	FireViewChange();
	return S_OK;
}


STDMETHODIMP CVeselov::get_MaxY(SHORT* pVal)
{
	// TODO: Add your implementation code here
	*pVal = maxY;
	return S_OK;
}


STDMETHODIMP CVeselov::put_MaxY(SHORT newVal)
{
	// TODO: Add your implementation code here
	maxY = newVal;
	FireViewChange();
	return S_OK;
}


STDMETHODIMP CVeselov::get_LineColor(OLE_COLOR* pVal)
{
	// TODO: Add your implementation code here
	*pVal = m_clrLineColor;
	return S_OK;
}


STDMETHODIMP CVeselov::put_LineColor(OLE_COLOR newVal)
{
	// TODO: Add your implementation code here
	m_clrLineColor = newVal;
	FireViewChange();
	return S_OK;
}


LRESULT CVeselov::OnLButtonDown(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
{
	// TODO: Add your message handler code here and/or call default	
	Fire_ClickLButton();
	if(!flagLButton){
		flagLButton = true;
		flagRButton = false;
		flagDBRButton = false;
		FireViewChange();
	}
	else{
		flagDBLButton = true;
		FireViewChange();
	}	
	return 0;
}


LRESULT CVeselov::OnRButtonDown(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
{
	// TODO: Add your message handler code here and/or call default
	Fire_ClickRButton();
	if(!flagRButton){
		flagLButton = false;
		flagDBLButton = false;
		flagRButton = true;
		FireViewChange();
	}
	else{
		flagDBRButton = true;
		FireViewChange();
	}
		
	return 0;
}
