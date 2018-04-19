// CLIENT.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	
	char* szProgID = "FN_12.Component.1" ;
	wchar_t* autor;
	WCHAR szWideProgID[128]; 
	CLSID clsid;
	IClassFactory* pCF;
	IUnknown* pUnk; 
	IFN_12* pFN_12 = NULL;
	IVer* pVer = NULL;
	int iRez, countObj;
	float fRez;
	if ( FAILED( CoInitialize( NULL ))) 
	{ 
		printf( "Unable to initialize COM \n");
		getch();
		return -1; 
	}
	else 
		printf("Initialize COM\n");
	
	long lLen = MultiByteToWideChar( CP_ACP, 0, szProgID,strlen( szProgID ), szWideProgID, sizeof( szWideProgID ) ); 
	szWideProgID[ lLen ] = '\0'; 
	HRESULT hr = ::CLSIDFromProgID( szWideProgID, &clsid );
	if ( FAILED( hr )) 
	{

		printf("Unable to get CLSID from ProgID. HR = %X \n",hr); 
		getch();
		return -1;
	} 
	//IFN_12* pIFN_12 = NULL;

	//hr = ::CoCreateInstance(clsid, NULL, CLSCTX_INPROC, IID_IFN_12,(void**) &pIFN_12);
	//printf("%X",hr);
	hr = ::CoGetClassObject( clsid, CLSCTX_INPROC, NULL,IID_IClassFactory, (void**) &pCF ); 
	if ( FAILED( hr )) 
	{ 
		printf("Failed to GetClassObject server instance. HR = %X \n",hr);
		getch();
		return -1; 
	} 

	
	hr = pCF->CreateInstance( NULL, IID_IUnknown, (void**) &pUnk ); 
	 if ( FAILED( hr )) 
	{ 
		printf("Failed to create server instance. HR =%X \n",hr); 
		getch();
		return -1; 
	} 
	 else
		 printf("Instance created \n");
	
	 hr = pUnk->QueryInterface( IID_IFN_12, (LPVOID*)&pFN_12 ); 
	 //pUnk->Release(); 
	 if ( FAILED( hr )) 
	 { 
		 printf("QueryInterface() for IMath failed \n"); return -1; 
	 }
	 hr = pUnk->QueryInterface( IID_IVER, (LPVOID*)&pVer);
	 if ( FAILED( hr )) 
	 { 
		 printf("QueryInterface() for IMath failed \n"); return -1; 
	 }
	 pUnk->Release();
	 pFN_12->Fun121(2.13,3.14,&iRez);
	 printf("\nFun121 2.13 * 3.14 = %d", iRez);

	 pFN_12->Fun122(3,5,8,&fRez);
	 printf("\nFun122 3 + 5 + 8 = %f", fRez);

	 pFN_12->Fun123(5,&iRez);
	 printf("\nFun123 5 * 5 = %d", iRez);
	 pFN_12->Release();
	 pVer->GetAutor(&autor);
	 wprintf(L"\nAutor: %s", autor);
	 countObj = pVer->Release();
	 if(!countObj>0)
		 printf("\n\nShuting down COM\n");
	 else
		 printf("\n\nRemains open COM\n");
	CoUninitialize();
	getch();
	return 0;
}

