// 
// Client.cpp 
// 
#include <windows.h>
#include <tchar.h> 
#include <stdio.h>
#include <conio.h>

#include <initguid.h>
#include "..\lab1_1\imath.h" 

int main( int argc, char *argv[] ) 
  { 
  printf( "Initializing COM \n"); 
  if ( FAILED( CoInitialize( NULL ))) 
  { 
	  printf( "Unable to initialize COM \n"); return -1; 
  } 
  char* szProgID = "Math.Component.1"; 
  WCHAR szWideProgID[128]; 
  CLSID clsid; 
  long lLen = MultiByteToWideChar( CP_ACP, 0, szProgID,strlen( szProgID ), szWideProgID, sizeof( szWideProgID ) ); 
  szWideProgID[ lLen ] = '\0'; 
  HRESULT hr = ::CLSIDFromProgID( szWideProgID, &clsid ); 
  if ( FAILED( hr )) 
  { 
	  printf("Unable to get CLSID from ProgID. HR = %X \n",hr); return -1;
  } 
  IClassFactory* pCF; 
  // Получить фабрику класса для CMath 
  hr = CoGetClassObject( clsid, CLSCTX_INPROC, NULL,IID_IClassFactory, (void**) &pCF ); 
  if ( FAILED( hr )) 
  { 
	  printf("Failed to GetClassObject server instance. HR = %X \n",hr); return -1; 
  } 
  
  // с помощью фабрики класса создать экземпляр 
  // компонента и получить интерфейс IUnknown. 
  
  IUnknown* pUnk; 
  hr = pCF->CreateInstance( NULL, IID_IUnknown, (void**) &pUnk ); 
  
  // Release the class factory pCF->Release(); 
  if ( FAILED( hr )) 
  { 
	  printf("Failed to create server instance. HR =%X \n",hr); return -1; 
  } 
  printf("Instance created \n"); 
  IMath* pMath = NULL; 
  hr = pUnk->QueryInterface( IID_IMath, (LPVOID*)&pMath ); 
  pUnk->Release(); 
  if ( FAILED( hr )) 
  { 
	  printf("QueryInterface() for IMath failed \n"); return -1; 
  } 
  
  long result; 

  pMath->Add(255,125,&result);
  printf("Func - Add: 255 + 125 is %d \n",result);

  pMath->Multiply( 30, 8, &result ); 
  printf("Func - Mltiply: 30 * 8 is %d \n",result); 

  pMath->Subtract( 200, 123, &result ); 
  printf("Func - Substract: 200 - 123 is %d \n",result);

  pMath->Divide(21,3,&result);
  printf("Func - Divide: 21 / 3 is %d \n",result);
  printf("Releasing instance \n"); 

  pMath->Release(); 
  printf("Shuting down COM\n"); 
  CoUninitialize();
  _getch();
  return 0; 
} 
