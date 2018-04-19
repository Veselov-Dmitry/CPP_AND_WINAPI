#include <Windows.h>
#include "REGISTRY.h"
#include "IMATH.h"


static HANDLE g_hModule = NULL ;   // DLL module handle

// Version-independent ProgID
const char g_szVerIndProgID[] = "Mathin.Component" ;

// ProgID
const char g_szProgID[] = "Mathin.Component.1" ;




BOOL APIENTRY DllMain(HANDLE hModule, DWORD dwReason, void* lpReserved)
{
	
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:	
		{
			
		}
		break;
	case DLL_THREAD_ATTACH:
		MessageBox(NULL,TEXT("Создается поток"),TEXT("Уведомление"),MB_OK);
		break;
	case DLL_THREAD_DETACH:
		MessageBox(NULL,TEXT("Поток коректно завершается"),TEXT("Уведомление"),MB_OK);
		break;
	case DLL_PROCESS_DETACH:		
		MessageBox(NULL,TEXT("Выгружыется библиотека Romash_DLL.dll. Проект Ромаш П.В."),TEXT("Уведомление"),MB_OK);
		break;
	}
	/*if (dwReason == DLL_PROCESS_ATTACH)
	{
		g_hModule = hModule ;
	}*/
	return TRUE ;
}

STDAPI DllRegisterServer()
{
	return RegisterServer((HMODULE)g_hModule, 
	                      CLSID_Math,
	                      g_szFriendlyName,
	                      g_szVerIndProgID,
	                      g_szProgID) ;
}


//
// Server unregistration
//
STDAPI DllUnregisterServer()
{
	return UnregisterServer(CLSID_Math,
	                        g_szVerIndProgID,
	                        g_szProgID) ;
}