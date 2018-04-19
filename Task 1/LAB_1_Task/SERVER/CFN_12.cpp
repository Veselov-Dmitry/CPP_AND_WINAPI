#include"stdafx.h"
#include"CFN_12.h"

//
// CFN_12 class implementation
//
// Constructors
CFN_12::CFN_12(){
	 m_lRef = 0;
	 InterlockedIncrement( &g_lObjs ); 
}
// Destructor
CFN_12::~CFN_12(){
	InterlockedDecrement( &g_lObjs ); 
}
// IUnknown->QueryInterface
STDMETHODIMP CFN_12::QueryInterface( REFIID riid, void** ppv )
{
    *ppv = 0;
 
    if ( riid == IID_IUnknown || riid == IID_IFN_12 )
        *ppv = static_cast<IFN_12*>(this);
	else if(riid == IID_IVER)
		*ppv = static_cast<IVer*>(this);
 
    if ( *ppv )
    {
        AddRef();
        return( S_OK );
    }
    return (E_NOINTERFACE);
}
// IUnknown->AddRef
STDMETHODIMP_(ULONG) CFN_12::AddRef()
{
   return InterlockedIncrement( &m_lRef );
}
// IUnknown->Release
STDMETHODIMP_(ULONG) CFN_12::Release()
{
   if ( InterlockedDecrement( &m_lRef ) == 0 )
   {
      delete this;
      return 0;
   }
 
   return m_lRef;
}
// function task 
 STDMETHODIMP CFN_12::Fun121 (double lOp1, double lOp2, int *out)
{  
	*out = lOp1 * lOp2;
   return( S_OK );
}

 STDMETHODIMP CFN_12::Fun122(int x, int y, int z, float *out){
	*out = x + y + z;
	 return( S_OK );	
}

 STDMETHODIMP CFN_12::Fun123(int in, int *out){
	*out = in * in;	
	return( S_OK );
}

 STDMETHODIMP CFN_12::GetAutor(wchar_t** autor){	
	*autor = L"Veselov - 50331";	
	return( S_OK );
 }

//
// class factory
//

FN_12ClassFactory::FN_12ClassFactory()
{
   m_lRef = 0;
}
 
FN_12ClassFactory::~FN_12ClassFactory()
{
}

STDMETHODIMP FN_12ClassFactory::QueryInterface( REFIID riid, void** ppv )
{
   *ppv = 0;
 
   if ( riid == IID_IUnknown || riid == IID_IClassFactory )
      *ppv = this;
 
   if ( *ppv )
   {
      AddRef();
      return S_OK;
   }
 
   return(E_NOINTERFACE);
}

STDMETHODIMP_(ULONG) FN_12ClassFactory::AddRef()
{
   return InterlockedIncrement( &m_lRef );
}

STDMETHODIMP_(ULONG) FN_12ClassFactory::Release()
{
   if ( InterlockedDecrement( &m_lRef ) == 0 )
   {
      delete this;
      return 0;
   }
 
   return m_lRef;
}

STDMETHODIMP FN_12ClassFactory::CreateInstance ( LPUNKNOWN pUnkOuter, REFIID riid, void** ppvObj )
{
   CFN_12* p—FN_12;
   HRESULT hr; 
   *ppvObj = 0; 
   p—FN_12 = new CFN_12; 
   if ( p—FN_12 == 0 )
      return( E_OUTOFMEMORY ); 
   hr = p—FN_12->QueryInterface( riid, ppvObj ); 
   if ( FAILED( hr ) )
      delete p—FN_12; 
   return hr;
}

STDMETHODIMP FN_12ClassFactory::LockServer( BOOL fLock )
{
   if ( fLock )
      InterlockedIncrement( &g_lLocks ); 
   else
      InterlockedDecrement( &g_lLocks );
 
    return S_OK;
}