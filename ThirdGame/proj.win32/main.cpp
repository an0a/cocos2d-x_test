#include "stdafx.h"
#include "main.h"
#include "AppDelegate.h"

#include "Log.h"


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

	LOG::InitAndCreateLogSystem();

    // create the application instance
    AppDelegate app;
    int ret = Application::getInstance()->run();

	LOG::DestroyLogSystem();

	return ret;
}
