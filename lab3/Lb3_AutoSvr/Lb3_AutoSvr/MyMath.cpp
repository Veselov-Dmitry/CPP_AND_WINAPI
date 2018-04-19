// MyMath.cpp : Implementation of CMyMath

#include "stdafx.h"
#include "MyMath.h"


// CMyMath



STDMETHODIMP CMyMath::Add(LONG op1, LONG op2, LONG* pResult)
{
	// TODO: Add your implementation code here
	*pResult = op1 + op2;
	return S_OK;
}


STDMETHODIMP CMyMath::Subtract(LONG op1, LONG op2, LONG* pResult)
{
	// TODO: Add your implementation code here
	*pResult = op1 - op2;
	return S_OK;
}


STDMETHODIMP CMyMath::Multiply(LONG op1, LONG op2, LONG* pResult)
{
	// TODO: Add your implementation code here
	*pResult = op1 * op2;
	return S_OK;
}


STDMETHODIMP CMyMath::Divide(LONG op1, LONG op2, LONG* pResult)
{
	// TODO: Add your implementation code here
	*pResult = op1 / op2;
	return S_OK;
}
