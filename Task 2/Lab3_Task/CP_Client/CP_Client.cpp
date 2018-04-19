// CP_Client.cpp : Defines the entry point for the application.
//

// реализация функции по доступу к методам через быстрое связывание по ID не реализованы
// реализация функции по доступу к методам через быстрое связывание по VTBL реализовано, но не работает
#include "stdafx.h"
#include "CP_Client.h"
#include "..\Lab3_Task_Server\Lab3_Task_Server_i.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

// HANDLE_MSG function
void Wnd_OnPaint(HWND);
BOOL Wnd_OnCreate(HWND, LPCREATESTRUCT);
void Wnd_OnDestroy(HWND);
void Wnd_OnCommand(HWND, int, HWND, UINT);

// Other function
TCHAR* StringClock(DWORD);

int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;

	// Initialize global strings
	//LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_CP_CLIENT, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CP_CLIENT));

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
//  COMMENTS:
//
//    This function and its usage are only necessary if you want this code
//    to be compatible with Win32 systems prior to the 'RegisterClassEx'
//    function that was added to Windows 95. It is important to call this function
//    so that the application will get 'well formed' small icons associated
//    with it.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CP_CLIENT));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_CP_CLIENT);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // Store instance handle in our global variable
   lstrcat(szTitle, TEXT("C++ CLIENT Veselov"));
   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{
		HANDLE_MSG(hWnd,WM_COMMAND,Wnd_OnCommand);	
		HANDLE_MSG(hWnd,WM_PAINT,Wnd_OnPaint);
		HANDLE_MSG(hWnd,WM_CREATE,Wnd_OnCreate);
		HANDLE_MSG(hWnd,WM_DESTROY,Wnd_OnDestroy);
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// HANDLE_MSG  

void Wnd_OnPaint(HWND hWnd){
	HDC hDC;
	PAINTSTRUCT ps;
	hDC = BeginPaint( hWnd, &ps );
	
    EndPaint( hWnd, &ps );
}



BOOL Wnd_OnCreate(HWND hWnd, LPCREATESTRUCT lpCreateStruct){
	HWND hEditParam1, hEditParam2, hEditParam3, hStaticParam1, hStaticParam2, hStaticParam3,hStaticFun121,hStaticFun122,hStaticFun123;
	HWND hEditFun121, hEditFun122,hEditFun123, hStaticTimeLate,hStaticTimeID, hStaticTimeVtbl, hEditTimeLate,hEditTimeID,hEditTimeVtbl;
	HWND hButtonLate, hButtonID, hButtonVtbl;
	// Edit
	hEditParam1 = CreateWindow(
			TEXT("edit"),
			NULL,
			WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT,
			30,
			60,
			WIDTH_EDIT,
			HEIGHT_EDIT,
			hWnd,
			(HMENU)IDC_EDIT_PARAM1,
			hInst, 
			NULL 
			);
		if(!hEditParam1) 
		{ 
			MessageBox(NULL,TEXT("Кнопка не создана!"), TEXT("Ошибка"),MB_OK|MB_ICONERROR); 
			return FALSE;
		}

		hEditParam2 = CreateWindow(
			TEXT("edit"),
			NULL,
			WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT,
			250,
			60,
			WIDTH_EDIT,
			HEIGHT_EDIT,
			hWnd,
			(HMENU)IDC_EDIT_PARAM2,
			hInst, 
			NULL 
			);
		if(!hEditParam2) 
		{ 
			MessageBox(NULL,TEXT("Кнопка не создана!"), TEXT("Ошибка"),MB_OK|MB_ICONERROR); 
			return FALSE;
		}

		hEditParam3 = CreateWindow(
			TEXT("edit"),
			NULL,
			WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT,
			470,
			60,
			WIDTH_EDIT,
			HEIGHT_EDIT,
			hWnd,
			(HMENU)IDC_EDIT_PARAM3,
			hInst, 
			NULL 
			);
		if(!hEditParam3) 
		{ 
			MessageBox(NULL,TEXT("Кнопка не создана!"), TEXT("Ошибка"),MB_OK|MB_ICONERROR); 
			return FALSE;
		}

		hEditFun121 = CreateWindow(
			TEXT("edit"),
			NULL,
			WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT,
			30,
			130,
			WIDTH_EDIT_MAX,
			HEIGHT_EDIT,
			hWnd,
			(HMENU)IDC_EDIT_FUN121,
			hInst, 
			NULL 
			);
		if(!hEditFun121) 
		{ 
			MessageBox(NULL,TEXT("Кнопка не создана!"), TEXT("Ошибка"),MB_OK|MB_ICONERROR); 
			return FALSE;
		}
		hEditFun122 = CreateWindow(
			TEXT("edit"),
			NULL,
			WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT,
			30,
			200,
			WIDTH_EDIT_MAX,
			HEIGHT_EDIT,
			hWnd,
			(HMENU)IDC_EDIT_FUN122,
			hInst, 
			NULL 
			);
		if(!hEditFun122) 
		{ 
			MessageBox(NULL,TEXT("Кнопка не создана!"), TEXT("Ошибка"),MB_OK|MB_ICONERROR); 
			return FALSE;
		}
		hEditFun123 = CreateWindow(
			TEXT("edit"),
			NULL,
			WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT,
			30,
			270,
			WIDTH_EDIT_MAX,
			HEIGHT_EDIT,
			hWnd,
			(HMENU)IDC_EDIT_FUN123,
			hInst, 
			NULL 
			);
		if(!hEditFun123) 
		{ 
			MessageBox(NULL,TEXT("Кнопка не создана!"), TEXT("Ошибка"),MB_OK|MB_ICONERROR); 
			return FALSE;
		}
		hEditTimeLate = CreateWindow(
			TEXT("edit"),
			NULL,
			WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT,
			30,
			340,
			WIDTH_EDIT,
			HEIGHT_EDIT,
			hWnd,
			(HMENU)IDC_EDIT_TIMELATE,
			hInst, 
			NULL 
			);
		if(!hEditTimeLate) 
		{ 
			MessageBox(NULL,TEXT("Кнопка не создана!"), TEXT("Ошибка"),MB_OK|MB_ICONERROR); 
			return FALSE;
		}

		hStaticParam1 = CreateWindow(
			TEXT("static"),
			NULL,
			WS_CHILD | WS_VISIBLE | SS_SIMPLE,
			30,
			30,
			100,
			20,
			hWnd,
			(HMENU)IDC_STATIC_PARAM1,
			hInst, 
			NULL 
			);
		
		if(!hStaticParam1) 
		{ 
			MessageBox(NULL,TEXT("Кнопка не создана!"), TEXT("Ошибка"),MB_OK|MB_ICONERROR); 
			return FALSE;
		}
		hStaticParam2 = CreateWindow(
			TEXT("static"),
			NULL,
			WS_CHILD | WS_VISIBLE | SS_SIMPLE,
			250,
			30,
			100,
			20,
			hWnd,
			(HMENU)IDC_STATIC_PARAM2,
			hInst, 
			NULL 
			);
		
		if(!hStaticParam2) 
		{ 
			MessageBox(NULL,TEXT("Кнопка не создана!"), TEXT("Ошибка"),MB_OK|MB_ICONERROR); 
			return FALSE;
		}
		hStaticParam3 = CreateWindow(
			TEXT("static"),
			NULL,
			WS_CHILD | WS_VISIBLE | SS_SIMPLE,
			470,
			30,
			100,
			20,
			hWnd,
			(HMENU)IDC_STATIC_PARAM3,
			hInst, 
			NULL 
			);
		
		if(!hStaticParam3) 
		{ 
			MessageBox(NULL,TEXT("Кнопка не создана!"), TEXT("Ошибка"),MB_OK|MB_ICONERROR); 
			return FALSE;
		}

		hStaticFun121 = CreateWindow(
			TEXT("static"),
			NULL,
			WS_CHILD | WS_VISIBLE | SS_SIMPLE,
			30,
			100,
			100,
			20,
			hWnd,
			(HMENU)IDC_STATIC_FUN121,
			hInst, 
			NULL 
			);
		
		if(!hStaticFun121) 
		{ 
			MessageBox(NULL,TEXT("Кнопка не создана!"), TEXT("Ошибка"),MB_OK|MB_ICONERROR); 
			return FALSE;
		}

		hStaticFun122 = CreateWindow(
			TEXT("static"),
			NULL,
			WS_CHILD | WS_VISIBLE | SS_SIMPLE,
			30,
			170,
			100,
			20,
			hWnd,
			(HMENU)IDC_STATIC_FUN122,
			hInst, 
			NULL 
			);
		
		if(!hStaticFun122) 
		{ 
			MessageBox(NULL,TEXT("Кнопка не создана!"), TEXT("Ошибка"),MB_OK|MB_ICONERROR); 
			return FALSE;
		}

		hStaticFun123 = CreateWindow(
			TEXT("static"),
			NULL,
			WS_CHILD | WS_VISIBLE | SS_SIMPLE,
			30,
			240,
			100,
			20,
			hWnd,
			(HMENU)IDC_STATIC_FUN123,
			hInst, 
			NULL 
			);
		
		if(!hStaticFun123) 
		{ 
			MessageBox(NULL,TEXT("Кнопка не создана!"), TEXT("Ошибка"),MB_OK|MB_ICONERROR); 
			return FALSE;
		}

		hStaticTimeLate = CreateWindow(
			TEXT("static"),
			NULL,
			WS_CHILD | WS_VISIBLE | SS_SIMPLE,
			30,
			310,
			100,
			20,
			hWnd,
			(HMENU)IDC_STATIC_TIMELATE,
			hInst, 
			NULL 
			);
		
		if(!hStaticTimeLate) 
		{ 
			MessageBox(NULL,TEXT("Кнопка не создана!"), TEXT("Ошибка"),MB_OK|MB_ICONERROR); 
			return FALSE;
		}
		hStaticTimeID = CreateWindow(
			TEXT("static"),
			NULL,
			WS_CHILD | WS_VISIBLE | SS_SIMPLE,
			250,
			310,
			100,
			20,
			hWnd,
			(HMENU)IDC_STATIC_TIMEID,
			hInst, 
			NULL 
			);
		
		if(!hStaticTimeID) 
		{ 
			MessageBox(NULL,TEXT("Кнопка не создана!"), TEXT("Ошибка"),MB_OK|MB_ICONERROR); 
			return FALSE;
		}

		SetWindowText(hStaticParam1,TEXT("Param 1"));
		SetWindowText(hStaticParam2,TEXT("Param 2"));
		SetWindowText(hStaticParam3,TEXT("Param 3"));
		SetWindowText(hStaticFun121,TEXT("Fun121"));
		SetWindowText(hStaticFun122,TEXT("Fun122"));
		SetWindowText(hStaticFun123,TEXT("Fun123"));
		SetWindowText(hStaticTimeLate,TEXT("Time LATE"));

		hButtonLate = CreateWindow(
			TEXT("button"),
			TEXT("LATE"),
			WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
			30,
			380,
			200,
			30,
			hWnd,
			(HMENU)IDC_BTN_LATE,
			hInst, 
			NULL 
			);
		if(!hButtonLate) 
			  { MessageBox(NULL,TEXT("Кнопка не создана!"), TEXT("Ошибка"),MB_OK|MB_ICONERROR); 
				return FALSE; 
			  }
	return TRUE;
}

	

void Wnd_OnDestroy(HWND hwnd){
	 PostQuitMessage( 12 );
}

void Wnd_OnCommand(HWND hWnd, int id, HWND hwndCtl, UINT codeNotify){
		// Parse the menu selections:
	static TCHAR bufParam1[10] = {0}, bufParam2[10] = {0}, bufParam3[10] = {0}, bufFun121[50] = {0}, bufFun122[50] = {0}, bufFun123[50] = {0}, *strTimeWork;
	int iParam1, iParam2, iParam3, *rezFun121 = NULL, i;
	LONG lRezFun121;
	double dParam1, dParam2, fun123, *rezFun123 = NULL, dRezFun123;
	float fRezFun122;
	FLOAT *rezFun122 = NULL;
	DWORD timeStart, timeWork;
	HRESULT hr = OleInitialize(NULL);
	wchar_t *progId = L"Lab3_Task.Fun.1";
	CLSID clsid;
	IDispatch* plDispatch = NULL;
	IUnknown* pIUnknow = NULL;
	DISPID dispidFun121, dispidFun122, dispidFun123;
	OLECHAR *olFun121 = L"Fun121", *olFun122 = L"Fun122", *olFun123 = L"Fun123";
	DISPPARAMS dispparamFun121, dispparamFun122, dispparamFun123;
	VARIANT inVarsFun121[2], outVarFun121[1];
	VARIANT inVarsFun122[3], outVarFun122[1];
	VARIANT inVarsFun123[1], outVarFun123[1];
	CoFun *coFun;
	
	switch (LOWORD(id))
	{		
		case IDC_BTN_LATE:
			SendMessage(GetDlgItem(hWnd,IDC_EDIT_PARAM1),WM_GETTEXT,10, (LPARAM)bufParam1);
			SendMessage(GetDlgItem(hWnd,IDC_EDIT_PARAM2),WM_GETTEXT,10, (LPARAM)bufParam2);
			SendMessage(GetDlgItem(hWnd,IDC_EDIT_PARAM3),WM_GETTEXT,10, (LPARAM)bufParam3);
			dParam1 = _wtof(bufParam1);
			dParam2 = _wtof(bufParam2);
			iParam1 = _wtoi(bufParam1);
			iParam2 = _wtoi(bufParam2);
			iParam3 = _wtoi(bufParam3);
			// Заполнение массива типа VARIANT
			// Входные параметры
			inVarsFun121[0].vt = VT_R8;
			inVarsFun121[0].dblVal = dParam1;
			inVarsFun121[1].vt = VT_R8;
			inVarsFun121[1].dblVal = dParam2;
			inVarsFun122[0].vt = VT_INT;
			inVarsFun122[0].intVal = iParam1;
			inVarsFun122[1].vt = VT_INT;
			inVarsFun122[1].intVal = iParam2;
			inVarsFun122[2].vt = VT_INT;
			inVarsFun122[2].intVal = iParam3;
			inVarsFun123[0].vt = VT_R8;
			inVarsFun123[0].dblVal = dParam1;
			// Выходные параметры
			outVarFun121[0].vt = VT_BYREF|VT_INT;
			outVarFun121[0].pintVal = rezFun121;
			outVarFun122[0].vt = VT_BYREF|VT_R4;
			outVarFun122[0].pfltVal = rezFun122;
			outVarFun123[0].vt = VT_BYREF|VT_R8;
			outVarFun123[0].pdblVal = rezFun123;
			// Заполнение структуры DISPPARAMS
			dispparamFun121.rgvarg = inVarsFun121;
			dispparamFun121.rgdispidNamedArgs = 0;
			dispparamFun121.cArgs = 2;
			dispparamFun121.cNamedArgs = 0;
			dispparamFun122.rgvarg = inVarsFun122;
			dispparamFun122.rgdispidNamedArgs = 0;
			dispparamFun122.cArgs = 3;
			dispparamFun122.cNamedArgs = 0;
			dispparamFun123.rgvarg = inVarsFun123;
			dispparamFun123.rgdispidNamedArgs = 0;
			dispparamFun123.cArgs = 1;
			dispparamFun123.cNamedArgs = 0;
			timeStart = GetTickCount();
			// Получение CLSID через ProgId прилжения  
			hr = ::CLSIDFromProgID(progId,&clsid);
			// Создаем компонент
			hr = ::CoCreateInstance(clsid,NULL,CLSCTX_INPROC_SERVER,IID_IDispatch,(void**)&plDispatch);
			// Получение диспетчерского идентификатора
			plDispatch->GetIDsOfNames(IID_NULL,&olFun121,1,GetUserDefaultLCID(),&dispidFun121);
			plDispatch->GetIDsOfNames(IID_NULL,&olFun122,1,GetUserDefaultLCID(),&dispidFun122);
			plDispatch->GetIDsOfNames(IID_NULL,&olFun123,1,GetUserDefaultLCID(),&dispidFun123);
			
			// Выполнение метода Invoke
			plDispatch->Invoke(dispidFun121,IID_NULL,GetUserDefaultLCID(),DISPATCH_METHOD,&dispparamFun121,outVarFun121,0,0);
			plDispatch->Invoke(dispidFun122,IID_NULL,GetUserDefaultLCID(),DISPATCH_METHOD,&dispparamFun122,outVarFun122,0,0);
			plDispatch->Invoke(dispidFun123,IID_NULL,GetUserDefaultLCID(),DISPATCH_METHOD,&dispparamFun123,outVarFun123,0,0);
			swprintf(bufFun121,L"%lf + %lf = %d",dParam1,dParam2,outVarFun121->intVal);
			swprintf(bufFun122,L"%d / %d / %d = %f",iParam1,iParam2, iParam3, outVarFun122->fltVal);
			swprintf(bufFun123,L"%lf * %lf = %lf",dParam1,dParam1,outVarFun123->dblVal);
			Edit_SetText(GetDlgItem(hWnd,IDC_EDIT_FUN121),bufFun121);
			Edit_SetText(GetDlgItem(hWnd,IDC_EDIT_FUN122),bufFun122);
			Edit_SetText(GetDlgItem(hWnd,IDC_EDIT_FUN123),bufFun123);
			for(int i = 0; i < ITERATIONS; i++){
				plDispatch->Invoke(dispidFun121,IID_NULL,GetUserDefaultLCID(),DISPATCH_METHOD,&dispparamFun121,outVarFun121,0,0);
				plDispatch->Invoke(dispidFun122,IID_NULL,GetUserDefaultLCID(),DISPATCH_METHOD,&dispparamFun122,outVarFun122,0,0);
				plDispatch->Invoke(dispidFun123,IID_NULL,GetUserDefaultLCID(),DISPATCH_METHOD,&dispparamFun123,outVarFun123,0,0);
			}
			//MessageBox(hWnd,TEXT("LATE"),NULL,MB_OK);
			plDispatch->Release();
			timeWork = GetTickCount() - timeStart;
			strTimeWork = StringClock(timeWork);
			Edit_SetText(GetDlgItem(hWnd,IDC_EDIT_TIMELATE),strTimeWork);
			break;
		case IDC_BTN_ID: // с примером программы через ID без использования метода GetIDsOfNames я не смог разобраться 			
			MessageBox(hWnd,TEXT("ID"),NULL,MB_OK);
			break;
		case IDC_BTN_VTBL:	
			break;
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
	}	
}



// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
TCHAR* StringClock(DWORD milisec){
	double wSec,wMin,wHour;
	int msec, min, sec;	
	static TCHAR stringClock[20] = {0};
	wSec = milisec/1000;
	wMin = milisec/1000 / 60;
	wHour = milisec/1000 / 60 / 60;
	min = wMin - (int)wHour * 60;
	sec = wSec - ((int)wHour * 60 * 60 + min * 60);
	msec = milisec - ((int)wHour * 60 * 60 * 1000 + min * 60 * 1000 + sec * 1000);
	swprintf(stringClock,L"%d:%d:%d.%d",(int)wHour,min,sec,msec);
	return stringClock;

}
