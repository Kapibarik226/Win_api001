

#include <windows.h>                    //  Подключаем (заголовочный файл ) библиотеки функций WinAPI  
//#include   <stdio.h>   
	void xPrint(int x, int y, const char *pChar);
	
	
int          Timer_CLK =   0;  	

char sz[122];


//////////////////////////////////////////  Глобальные переменные 
HWND                  hWnd;             //  хедер ГЛАВНОГО! окна  
HINSTANCE        hInstance; 			//  Экземпляр этой программы 


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)   //  Функция обработки сообщений от...
{																				  //  ...OS Windows	
	switch(message)
	{
		case  WM_CREATE:   SetTimer(hWnd, 1, 200, 0);  
			
			               break;                          //  Принимаем однократное сообщение для инициализации
	    case WM_DESTROY:   PostQuitMessage(0);             //  Принимаем однократное сообщение для ДЕ_инициализации
		 	 			   break;
							 		 	 		
		case WM_COMMAND:   switch(LOWORD(wParam))
	                    {
			               case 110:xPrint(250,20,"2+3 = ?"); 
			               
						   HWND hwndButton = CreateWindow( 
                           "BUTTON",  // Predefined class; Unicode assumed 
                           "10?",      // Button text 
                           WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
                           200,         // x position 
                           70,         // y position 
                           100,        // Button width
                           22,        // Button height
                           hWnd,      // Parent window
                           (HMENU)1,
	                       //0,       // No menu.
                           //(HINSTANCE)GetWindowLongPtr(hWnd, hInstance),
	                       hInstance, 
                           0);
                           
                           HWND hwndButton1 = CreateWindow( 
                           "BUTTON",  // Predefined class; Unicode assumed 
                           "5?",      // Button text 
                           WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
                           300,         // x position 
                           70,         // y position 
                           100,        // Button width
                           22,        // Button height
                           hWnd,      // Parent window
                           (HMENU)1,
	                       //0,       // No menu.
                           //(HINSTANCE)GetWindowLongPtr(hWnd, hInstance),
	                       hInstance, 
                           0);
			               break;
						} 
						break;
	    case WM_TIMER:	   		               
						break;
						   				 
							 	   
		        default:   return DefWindowProc(hWnd, message, wParam, lParam);   // обработка OS остальных сообщений
	}
	return 0;
}

//---------------------------------------------------------------------------------------------------------------------

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInstance, LPSTR lpszCmd, int nCmdShow)
{
	
	WNDCLASS WndClass;             // Создаём элемент оконной структуры	
			 WndClass.style         = 0;
			 WndClass.lpfnWndProc   = WndProc;                                 //   Имя оконной функции
			 WndClass.cbClsExtra    = 0;
			 WndClass.cbWndExtra    = 0;
			 WndClass.hInstance     = hInstance = hInst;                       //   Дескриптор приложения
			 WndClass.hIcon		    = LoadIcon(hInstance, "MYICON");           //   Загружаем иконку
			 WndClass.hCursor	    = LoadCursor(NULL, IDC_ARROW);             //   Загружаем тип курсора 
			 WndClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);      //   Цвет заливки окна выбрали
			 WndClass.lpszMenuName  = "xMENU";                                 //   Указываем имя меню 
			 WndClass.lpszClassName = "dllBridge";                             //   Придумали сами имя класса окна  
                                                    // Cначала регистрируем класс главного окна программы  
	if(!RegisterClass(&WndClass)) return 0;         // если класс не зарегистрирован, то выходим 
	
	hWnd = CreateWindow("dllBridge",                // ————— создаем окно класса dllBridge —————
						"Lessons",                  // заголовок окна (надпись на верхней-синей полосе)
						WS_OVERLAPPEDWINDOW,        // стиль окна
						700,              // координата X левого верхнего угла окна 
						200,              // координата Y левого верхнего угла окна 
						648,                        // размеры окна (Ширина)
					    526,                        // Высота
					      0,                        // Дескриптор родительского окна  ( нет главного окна программы :)
					      0,                        // Дескриптор  меню  (или идентификатор дочернего окна)
					    hInstance,                  // Дескриптор экземпляра приложения
					      0);                      
	if(hWnd == 0) return 0;							    //  если окно не создано, то выходим (программа не запустилась)
	ShowWindow(hWnd, nCmdShow);						//  отобразить окно на экране
	UpdateWindow(hWnd);								//  обновить окно       								  									   								   


/*
    HWND hwndButton = CreateWindow( 
    "BUTTON",  // Predefined class; Unicode assumed 
    "YES",      // Button text 
    WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
    10,         // x position 
    10,         // y position 
    100,        // Button width
    22,        // Button height
    hWnd,      // Parent window
    (HMENU)1,
	//0,       // No menu.
    //(HINSTANCE)GetWindowLongPtr(hWnd, hInstance),
	hInstance, 
    0);
    
    
	HWND _hwndButton = CreateWindow( 
    "BUTTON",  // Predefined class; Unicode assumed 
    "NO",      // Button text 
    WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
    100,         // x position 
    10,         // y position 
    100,        // Button width
    22,        // Button height
    hWnd,      // Parent window
    (HMENU)20,
	//0,       // No menu.
    //(HINSTANCE)GetWindowLongPtr(hWnd, hInstance),
	hInstance, 
    0);      // Pointer not needed.	
      // Pointer not needed.	
*/
               MSG      msg;                        //  Создаём элемент структуры сообщений от OS Windows
	while(  GetMessage(&msg, 0, 0, 0))              //  Цикл обработки сообщений	
	{ TranslateMessage(&msg);                       //  Принятие и "проталкивание" сообщений в очереди
	   DispatchMessage(&msg);
	} 
	
	


return msg.wParam;
}


/*
if(20 == LOWORD(wParam) )
						   {
								
							   xPrint(100, 130, "No....");	
						   }				
			                
			               
			               if(1 == LOWORD(wParam) )
						   {
								
							   xPrint(100, 150, "Yes you are right");	
						   }				
			               break;
			               */









	void xPrint(int x, int y, const char *pChar)
	{
		
		
		 HDC       hdc;
		 //y  += ToolBar;                                            //  Поправка по вертикали (учитываем высоту ToolBar)
	     hdc = GetDC(hWnd);
		 SetTextColor(hdc, RGB( 186, 137,  95)); 
		 SetBkColor  (hdc, 0); 
		// (HFONT)SelectObject(hdc, hFont[9]);	
		 TextOut(hdc, x, y, pChar, strlen(pChar));
		 ReleaseDC(hWnd, hdc);
	}
	
	















