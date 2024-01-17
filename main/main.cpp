

#include <windows.h>                    //  ���������� (������������ ���� ) ���������� ������� WinAPI  
//#include   <stdio.h>   
	void xPrint(int x, int y, const char *pChar);
	
	
int          Timer_CLK =   0;  	

char sz[122];


//////////////////////////////////////////  ���������� ���������� 
HWND                  hWnd;             //  ����� ��������! ����  
HINSTANCE        hInstance; 			//  ��������� ���� ��������� 


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)   //  ������� ��������� ��������� ��...
{																				  //  ...OS Windows	
	switch(message)
	{
		case  WM_CREATE:   SetTimer(hWnd, 1, 200, 0);  
			
			               break;                          //  ��������� ����������� ��������� ��� �������������
	    case WM_DESTROY:   PostQuitMessage(0);             //  ��������� ����������� ��������� ��� ��_�������������
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
						   				 
							 	   
		        default:   return DefWindowProc(hWnd, message, wParam, lParam);   // ��������� OS ��������� ���������
	}
	return 0;
}

//---------------------------------------------------------------------------------------------------------------------

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInstance, LPSTR lpszCmd, int nCmdShow)
{
	
	WNDCLASS WndClass;             // ������ ������� ������� ���������	
			 WndClass.style         = 0;
			 WndClass.lpfnWndProc   = WndProc;                                 //   ��� ������� �������
			 WndClass.cbClsExtra    = 0;
			 WndClass.cbWndExtra    = 0;
			 WndClass.hInstance     = hInstance = hInst;                       //   ���������� ����������
			 WndClass.hIcon		    = LoadIcon(hInstance, "MYICON");           //   ��������� ������
			 WndClass.hCursor	    = LoadCursor(NULL, IDC_ARROW);             //   ��������� ��� ������� 
			 WndClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);      //   ���� ������� ���� �������
			 WndClass.lpszMenuName  = "xMENU";                                 //   ��������� ��� ���� 
			 WndClass.lpszClassName = "dllBridge";                             //   ��������� ���� ��� ������ ����  
                                                    // C������ ������������ ����� �������� ���� ���������  
	if(!RegisterClass(&WndClass)) return 0;         // ���� ����� �� ���������������, �� ������� 
	
	hWnd = CreateWindow("dllBridge",                // ����� ������� ���� ������ dllBridge �����
						"Lessons",                  // ��������� ���� (������� �� �������-����� ������)
						WS_OVERLAPPEDWINDOW,        // ����� ����
						700,              // ���������� X ������ �������� ���� ���� 
						200,              // ���������� Y ������ �������� ���� ���� 
						648,                        // ������� ���� (������)
					    526,                        // ������
					      0,                        // ���������� ������������� ����  ( ��� �������� ���� ��������� :)
					      0,                        // ����������  ����  (��� ������������� ��������� ����)
					    hInstance,                  // ���������� ���������� ����������
					      0);                      
	if(hWnd == 0) return 0;							    //  ���� ���� �� �������, �� ������� (��������� �� �����������)
	ShowWindow(hWnd, nCmdShow);						//  ���������� ���� �� ������
	UpdateWindow(hWnd);								//  �������� ����       								  									   								   


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
               MSG      msg;                        //  ������ ������� ��������� ��������� �� OS Windows
	while(  GetMessage(&msg, 0, 0, 0))              //  ���� ��������� ���������	
	{ TranslateMessage(&msg);                       //  �������� � "�������������" ��������� � �������
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
		 //y  += ToolBar;                                            //  �������� �� ��������� (��������� ������ ToolBar)
	     hdc = GetDC(hWnd);
		 SetTextColor(hdc, RGB( 186, 137,  95)); 
		 SetBkColor  (hdc, 0); 
		// (HFONT)SelectObject(hdc, hFont[9]);	
		 TextOut(hdc, x, y, pChar, strlen(pChar));
		 ReleaseDC(hWnd, hdc);
	}
	
