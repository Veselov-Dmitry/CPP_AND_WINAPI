// SERVER.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "CFN_12.h"
#include "REGISTRY.h"

long    g_lObjs = 0;
long    g_lLocks = 0;


// Friendly name of component
const char g_szFriendlyName[] = "TCP_Task1 FN_12 Component" ;

// Version-independent ProgID
const char g_szVerIndProgID[] = "FN_12.Component" ;

// ProgID
const char g_szProgID[] = "FN_12.Component.1" ;


STDAPI DllGetClassObject( REFCLSID rclsid, REFIID riid, void** ppv )
{
   HRESULT             hr;
   FN_12ClassFactory    *pCF;
 
   pCF = 0;
 
   // Make sure the CLSID is for our Expression component
   if ( rclsid != CLSID_FN_12 )
      return( E_FAIL ); 
   pCF = new FN_12ClassFactory;
 
   if ( pCF == 0 )
      return( E_OUTOFMEMORY );
 
   hr = pCF->QueryInterface( riid, ppv );
 
   // Check for failure of QueryInterface
   if ( FAILED( hr ) )
   {
      delete pCF;
      pCF = 0;
   }
 
   return hr;
}
 
STDAPI DllCanUnloadNow(void)
{
    if ( g_lObjs || g_lLocks )
       return( S_FALSE );
    else
       return( S_OK );
}

STDAPI DllRegisterServer()
{
	return RegisterServer(g_hModule, 
	                      CLSID_FN_12,
	                      g_szFriendlyName,
	                      g_szVerIndProgID,
	                      g_szProgID) ;
}
STDAPI DllUnregisterServer()
{
	return UnregisterServer(CLSID_FN_12,
	                        g_szVerIndProgID,
	                        g_szProgID) ;
}