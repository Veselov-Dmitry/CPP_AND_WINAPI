// Fun.cpp : Implementation of CFun

#include "stdafx.h"
#include "Fun.h"


// CFun




//STDMETHODIMP CFun::Fun121(DOUBLE op1, DOUBLE op2, SHORT* pResult){
//	return S_OK;
//}

STDMETHODIMP CFun::Fun121(DOUBLE op1, DOUBLE op2, LONG* pResult)
{
	// TODO: Add your implementation code here
	*pResult = op1 + op2;
	return S_OK;
}


//STDMETHODIMP CFun::Fun122(LONG op1, LONG op2, LONG* pResult)
//{
//	// TODO: Add your implementation code here
//	*pResult = op1 / op2;
//	return S_OK;
//}


STDMETHODIMP CFun::Fun123(DOUBLE op1, DOUBLE* pResult)
{
	// TODO: Add your implementation code here
	*pResult = op1 * op1;
	return S_OK;
}


STDMETHODIMP CFun::Fun122(LONG op1, LONG op2, LONG op3, FLOAT* pResult)
{
	// TODO: Add your implementation code here
	*pResult = (float)op1 / (float)op2 / (float)op3;
	return S_OK;
}
// Fun.cpp : implementation file
//




