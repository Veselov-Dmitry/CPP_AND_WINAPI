//===============sp_pr2.h=======
#define CLASS_NAME TEXT ("sp_pr2_class");//для указателя на строку с именем класса окна
#define APPLICATION_TITLE TEXT ("Главное окно приложения. Программист <Веселов Дмитрий>");//указателя ... используемую для заголовка окна
#define DESTROY_MESSAGE TEXT ("Разрушается окно. В связи с этим поступило сообщение WM_DESTROY, из обработчика которого и выполнен данный вывод");//Этот текст необходимо использовать при выводе сообщения о закрытии окна
#define BUTTONDOWN_MESSAGE TEXT ("Обработка сообщения WM_LBUTTONDOWN, которое посылается в окно при щелчке левой кнопки мыши");
#define HEIGHT_WINDOW 400;
#define WIDTH_WINDOW 900;
//==============================
#include <windows.h>
#include <Windowsx.h>
#include <tchar.h>
//#include "sp_pr2.h"
																			// Глобальные переменные:
BOOL	InitInstance(HINSTANCE, int);
LRESULT CALLBACK Pr2_WndProc(HWND, UINT, WPARAM, LPARAM);
#define MAX_LOADSTRING 100
WCHAR szWindowClass[MAX_LOADSTRING];										// имя класса главного окна
HINSTANCE g_hInst;															// текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];												// Текст строки заголовка

HINSTANCE hInst;															// текущий экземпляр

LPCTSTR Message = TEXT("Вывод текста при обработке сообщения WM_PAINT. Это соообщение окно получает после того, как оно было закрыто другим окном и затем открыто.");
LPCTSTR g_lpszDestroyMessage = DESTROY_MESSAGE;

int APIENTRY _tWinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPTSTR lpszCmdLine,
	int nCmdShow
	){
	LPCTSTR g_lpszClassName = CLASS_NAME;									//указателя на строку с именем класса окна

	WNDCLASSEX wc;
	MSG msg;
	HWND hWnd;
	HWND hWndD;


	memset(&wc, 0, sizeof(WNDCLASSEX));
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.lpszClassName = TEXT("SimpleClassName");
	wc.lpfnWndProc = Pr2_WndProc;											//В качестве ее имени

	wc.lpszClassName = g_lpszClassName;										//на строку с именем класса
	wc.style = CS_VREDRAW | CS_HREDRAW;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, MAKEINTRESOURCE(IDI_SHIELD));
	wc.hCursor = LoadCursor(NULL, MAKEINTRESOURCE(IDC_ARROW));
	wc.hbrBackground = CreateSolidBrush(RGB(208, 208, 208));
	wc.lpszMenuName = NULL;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	if (!RegisterClassEx(&wc))
	{
		MessageBox(NULL, TEXT("Ошибка регистрации класса окна!"), TEXT("Ошибка"), MB_OK | MB_ICONERROR);
		return FALSE;														//и завершение работы в случае, когда регистрация класса выполнена с ошибкой
	}

																			// Выполнить инициализацию приложения:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}
	BOOL bRet;
	while ((bRet = GetMessage(&msg, NULL, 0, 0)) != 0)						//создайте цикл обработки сообщений
	{
		if (bRet == -1)
		{
																			// обработка ошибки и возможный выход из программы
		}
		TranslateMessage(&msg);												// принять ввод символьной информации от клавиатуры
		DispatchMessage(&msg);												//если дескриптор окна имеет флажок - HWND_TOPMOST  посылает сообщение оконным процедурам всех окон верхнего уровня в системе // если HWND_TOPMOST NULL не делает ничего
	}
	return msg.wParam;
}

BOOL InitInstance(
	HINSTANCE hInstance, 
	int nCmdShow
	){
	hInst = hInstance;														// Сохранить дескриптор экземпляра в глобальной переменной
	LPCTSTR g_lpszApplicationTitle = APPLICATION_TITLE;						//переменную с именем
	LPCTSTR g_lpszClassName = CLASS_NAME;									//указателя на строку с именем класса окна
	int u_ww = WIDTH_WINDOW;
	int u_hw = HEIGHT_WINDOW;

	
	HWND hWnd = CreateWindowEx(
		NULL,
		g_lpszClassName,
		g_lpszApplicationTitle,
		WS_OVERLAPPEDWINDOW, 400,											//смещение по горизонтали
		100,																//смещение по вертикали
		u_ww,																//ширина
		u_hw,																//высота
		NULL, NULL, hInstance, NULL);

	if (!hWnd)																//Предусмотрите проверку результата
	{
		MessageBox(
			NULL,
			TEXT("Окно не создано!"),
			TEXT("Ошибка"),
			MB_OK | MB_ICONERROR
			);
		return FALSE;														//и завершение работы в случае, когда регистрация класса выполнена с ошибкой
	}
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	return TRUE;
}
LPCTSTR textLDMouse = TEXT("Обработка сообщения WM_LBUTTONDOWN, которое посылается в окно при щелчке левой кнопки мыши");
LRESULT CALLBACK Pr2_WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	HDC hDC;
	switch (msg)
	{
	case WM_LBUTTONDOWN:
		hDC = GetDC(hWnd);

		TextOut(hDC, 50, 200, textLDMouse, lstrlen(textLDMouse));
		break;

	case WM_PAINT:
		PAINTSTRUCT ps;
		hDC = BeginPaint(hWnd, &ps);
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		MessageBox(NULL, g_lpszDestroyMessage, TEXT("Сообщение"), MB_OK);
		PostQuitMessage(5);
		break;
	default:
		return(DefWindowProc(hWnd, msg, wParam, lParam));

	}
	return FALSE;
}


//LRESULT CALLBACK Pr2_WndProc(
//	HWND hWnd,
//	UINT msg,
//	WPARAM wParam,
//	LPARAM lParam
//	){
//	HDC hDC;
//	static HWND hButtonSave;												//В буфер
//	static HWND hButtonAdd;													//В список
//	static HWND hEdit;														//текстовое поле
//	static HWND hListBox;													//поле listBox
//	static HWND hButtonExit;												//Выход
//	#define IDC_BTN_SAVE 100
//	#define IDC_BTN_ADD 101
//	#define IDC_EDIT1 102
//	#define IDC_LISTBOX 103
//
//	LPCTSTR g_lpszDestroyMessage = DESTROY_MESSAGE;							// переменную именем g_lpszDestroyMessage
//	TCHAR text[] = BUTTONDOWN_MESSAGE;
//	int cntMsg = ARRAYSIZE(text);
//	int xPos;
//	int yPos;
//
//	switch (msg){
//																			//case WM_LBUTTONDOWN: {
//																			//	hDC = GetWindowDC(hWnd);//извлекает контекст устройства (DC) для всего окна
//																			//	TextOut(hDC,/*дескриптор DC*/50,/*x-координата начальной позиции*/200,/*y-координата начальной позиции*/text,/*строка символов*/cntMsg/*число символов*/);
//																			//	ReleaseDC(hWnd, hDC);//освободить контекст устройства
//																			//	break;
//	case WM_LBUTTONDOWN: {
//		RECT rect;
//		GetClientRect(hWnd, &rect);
//		InvalidateRect(hWnd, 0, TRUE);
//		UpdateWindow(hWnd);
//
//		xPos = GET_X_LPARAM(lParam);										//#include <Windowsx.h>
//		yPos = GET_Y_LPARAM(lParam);
//		RECT r;
//		r.top = yPos;
//		r.left = xPos;
//		r.bottom = HEIGHT_WINDOW - yPos - 20;
//		r.right = WIDTH_WINDOW - xPos - 200;
//		UINT uFormat = DT_CENTER; 											//формат: Центрирует текст горизонтально в прямоугольнике
//		hDC = GetWindowDC(hWnd);											//извлекает контекст устройства (DC) для всего окна
//		DrawText(															//рисует отформатированный текст в заданном прямоугольнике
//			hDC,														// дескриптор контекста устройства
//			text,														// текст для вывода
//			cntMsg,														// длина текста
//			&r,															// размеры поля форматирования
//			uFormat														// параметры вывода текста
//			);
//		ReleaseDC(hWnd, hDC);												//освободить контекст устройства
//		break;
//	}/**/
//	case WM_COMMAND:{
//		int wmId = LOWORD(wParam);											//извлекает младшее слово из заданной величины
//		int wmEvent = HIWORD(wParam);										//извлекает старшее слово из данного 32-разрядного значения
//		static TCHAR pszTextBuff[500];
//		switch (wmId){
//			case IDCANCEL:{
//				DestroyWindow(hWnd);
//				break;
//			}
//			case IDC_BTN_SAVE:{
//				int cch;
//				cch = SendMessage(hEdit, WM_GETTEXT, 500, (LPARAM)pszTextBuff);	// отправляет заданное сообщение окну
//				if (cch == 0)
//					MessageBox(hWnd, TEXT("Введите текст"), TEXT("Читаем Edit"), MB_OK);
//				else {
//					TCHAR Buff1[500] = { 0 };
//					SYSTEMTIME st; GetSystemTime(&st);
//					wsprintf(Buff1, TEXT("Время : %d ч %d мин %d сек\n"), st.wHour, st.wMinute, st.wSecond);
//					lstrcat(Buff1, __TEXT("Текст в памяти: "));
//					lstrcat(Buff1, pszTextBuff);
//					MessageBox(hWnd, Buff1, TEXT("Содержимое буфера"), MB_OK);
//				}
//			break;
//			}
//			case IDC_BTN_ADD:{
//				int ind;
//				ind = SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM)pszTextBuff);
//				if (ind == LB_ERR)
//					MessageBox(hWnd, TEXT ("Ошибка в списке"), TEXT (""), MB_OK);
//			break;
//			}
//			default: {
//			return DefWindowProc(hWnd, msg, wParam, lParam);
//		}
//		}
//	break;
//	}
//	case WM_CREATE:	{
//		if (!(hEdit = CreateWindowEx(
//			0L, 
//			TEXT("Edit"), 
//			TEXT("Редактор"),
//			WS_CHILD | WS_BORDER | WS_VISIBLE, 
//			20, 
//			50, 
//			160,
//			40,
//			hWnd, 
//			(HMENU)(IDC_EDIT1), 
//			g_hInst, 
//			NULL))) 
//		return (-1);
//		if (!(hListBox = CreateWindowEx(
//			0L, 
//			TEXT("ListBox"), 
//			TEXT("Список"),
//			WS_CHILD | WS_BORDER | WS_VISIBLE,
//			200, 
//			50, 
//			160, 
//			180, 
//			hWnd, 
//			(HMENU)(IDC_LISTBOX),
//			g_hInst, 
//			NULL))) 
//			return (-1);
//		if (!(hButtonSave = CreateWindowEx(
//			0L, 
//			TEXT("Button"),
//			TEXT("В буфер"),
//			WS_CHILD | WS_BORDER | WS_VISIBLE,
//			20, 
//			240, 
//			80, 
//			24, 
//			hWnd, 
//			(HMENU)(IDC_BTN_SAVE),
//			g_hInst,
//			NULL))) 
//			return (-1);
//		if (!(hButtonAdd = CreateWindowEx(
//			0L, 
//			TEXT("Button"),
//			TEXT("В список"),
//			WS_CHILD | WS_BORDER | WS_VISIBLE,
//			120, 
//			240,
//			80, 
//			24, 
//			hWnd,
//			(HMENU)(IDC_BTN_ADD),
//			g_hInst,
//			NULL))) 
//			return (-1);
//		if (!(hButtonExit = CreateWindowEx(
//			0L, 
//			TEXT("Button"), 
//			TEXT("Выход"),
//			WS_CHILD | WS_BORDER | WS_VISIBLE,
//			220, 
//			240,
//			80,
//			24, 
//			hWnd,
//			(HMENU)(IDCANCEL),
//			g_hInst, 
//			NULL))) 
//			return (-1);
//		return 0; 
//	}
//																			//case WM_CREATE:	{
//																			//	LPCREATESTRUCT lpc;
//																			//	MessageBox(hWnd, TEXT("Выполняется обработка WM_CREATE"), NULL, MB_OK);
//																			//	return 0;
//																			//	//return -1;//при таком возврате выполняется WM_DESTROY
//																			//}
//	case WM_PAINT: {
//		PAINTSTRUCT ps;
//		TCHAR szHello[] = TEXT(" Hello World!");
//		//LoadString(														//загружает ресурс строки копирует строку в буфер и добавляет в конец \0
//		//	g_hInst,														//Дескриптор экземпляра модуля, исполняемый файл которого содержит в себе ресурс строки
//		//	sizeof(szHello) / sizeof(TCHAR),								// Указывает целочисленный идентификатор строки
//		//	szHello,														//Указатель на буфер
//		//	ARRAYSIZE(szHello));											// Определяет размер буфера
//		hDC = BeginPaint(hWnd, &ps);										// готовит заданное окно к окрашиванию// TODO: Add any drawing code here...
//		RECT rt;															//координаты
//		GetClientRect(hWnd, &rt);											//Retrieves the coordinates of a window's client area
//		DrawText(
//			hDC, 
//			szHello,
//			ARRAYSIZE(szHello),
//			&rt,
//			DT_CENTER);
//		EndPaint(hWnd, &ps);												//отмечает конец окрашивания в заданном окне
//		break;
//	}
//																			//case WM_PAINT:{    // Вывод при обновлении окна
//																			//	PAINTSTRUCT ps;
//																			//	hDC = BeginPaint(hWnd, &ps); // Получение контекста для  обновления окна 
//																			//	TextOut(hDC, 10, 10, TEXT("Hello, World!"), 13); // Вывод в контекст
//																			//	EndPaint(hWnd, &ps); // Завершение обновления окна
//																			//	break;
//																			//}
//	case WM_DESTROY:{														// Завершение работы приложения
//		MessageBox(
//			NULL,
//			g_lpszDestroyMessage,
//			TEXT("Cообщение"),
//			MB_OK | MB_ICONINFORMATION
//			);
//		PostQuitMessage(0);													// Посылка WM_QUIT приложению
//		break;
//	}
//
//	default:																// Вызов "Обработчика по умолчанию"
//		return(DefWindowProc(hWnd, msg, wParam, lParam));
//	}
//	return FALSE;															// Для ветвей с "break"
//}
