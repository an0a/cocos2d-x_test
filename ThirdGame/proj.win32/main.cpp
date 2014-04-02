#include "stdafx.h"
#include "main.h"
#include "AppDelegate.h"



USING_NS_CC;

int APIENTRY _tWinMain(HINSTANCE hInstance,
                       HINSTANCE hPrevInstance,
                       LPTSTR    lpCmdLine,
                       int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);



	{
		HWND hWnd = FindWindow( L"GLFW30", L"My Game" );

		if ( hWnd )
			PostMessage( hWnd, WM_QUIT, 0, 0 );
	}

	// 콘솔 생성.
	::AllocConsole();
	SetStdHandle( STD_ERROR_HANDLE, (HANDLE)GetStdHandle(STD_OUTPUT_HANDLE) );

    // create the application instance
    AppDelegate app;
    return Application::getInstance()->run();
}
