#include <windows.h>
#include "ÑÌÀÒÍ.h"
 
//
// Math class implementation
//
// Constructors
ÑMath::ÑMath()
{
   m_lRef = 0;
 
   // Óâåëè÷èòü çíà÷åíèå âíåøíåãî ñ÷åò÷èêà îáúåêòîâ
   InterlockedIncrement( &g_lObjs ); 
}
 
// The destructor
ÑMath::~ÑMath()
{
   // Óìåíüøèòü çíà÷åíèå âíåøíåãî ñ÷åò÷èêà îáúåêòîâ
   InterlockedDecrement( &g_lObjs ); 
}

STDMETHODIMP ÑMath::QueryInterface( REFIID riid, void** ppv )
{
    *ppv = 0;
 
    if ( riid == IID_IUnknown || riid == IID_IMath )
        *ppv = this;
 
    if ( *ppv )
    {
        AddRef();
        return( S_OK );
    }
    return (E_NOINTERFACE);
}
 
STDMETHODIMP_(ULONG) ÑMath::AddRef()
{
   return InterlockedIncrement( &m_lRef );
}
 
STDMETHODIMP_(ULONG) ÑMath::Release()
{
   if ( InterlockedDecrement( &m_lRef ) == 0 )
   {
      delete this;
      return 0;
   }
 
   return m_lRef;
}

STDMETHODIMP ÑMath::Add( long lOp1, long lOp2, long* pResult )
{
   *pResult = lOp1 + lOp2;
   return S_OK;
}
 
STDMETHODIMP ÑMath::Subtract( long lOp1, long lOp2, long* pResult )
{
   *pResult = lOp1 - lOp2;
   return S_OK;
}
 
STDMETHODIMP ÑMath::Multiply( long lOp1, long lOp2, long* pResult )
{
   *pResult = lOp1 * lOp2;
   return S_OK;
}
 
STDMETHODIMP ÑMath::Divide( long lOp1, long lOp2, long* pResult )
{
   *pResult = lOp1 / lOp2;
   return S_OK;
}

// Ðåàëèçàöèÿ MathClassFactory

MathClassFactory::MathClassFactory()
{
   m_lRef = 0;
}
 
MathClassFactory::~MathClassFactory()
{
}
 
STDMETHODIMP MathClassFactory::QueryInterface( REFIID riid, void** ppv )
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
 
STDMETHODIMP_(ULONG) MathClassFactory::AddRef()
{
   return InterlockedIncrement( &m_lRef );
}
 
STDMETHODIMP_(ULONG) MathClassFactory::Release()
{
   if ( InterlockedDecrement( &m_lRef ) == 0 )
   {
      delete this;
      return 0;
   }
 
   return m_lRef;
}
 
STDMETHODIMP MathClassFactory::CreateInstance ( LPUNKNOWN pUnkOuter, REFIID riid, void** ppvObj )
{
   ÑMath* pMath;
   HRESULT hr;
 
   *ppvObj = 0;
 
   pMath = new ÑMath;
 
   if ( pMath == 0 )
      return( E_OUTOFMEMORY );
 
   hr = pMath->QueryInterface( riid, ppvObj );
 
   if ( FAILED( hr ) )
      delete pMath;
 
   return hr;
}
 
STDMETHODIMP MathClassFactory::LockServer( BOOL fLock )
{
   if ( fLock )
      InterlockedIncrement( &g_lLocks ); 
   else
      InterlockedDecrement( &g_lLocks );
 
    return S_OK;
}



