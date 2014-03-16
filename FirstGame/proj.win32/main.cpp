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
		HWND hWnd = FindWindow( "GLFW30", "My Game" );

		if ( hWnd )
			PostMessage( hWnd, WM_QUIT, 0, 0 );
	}


    // create the application instance
    AppDelegate app;
    return Application::getInstance()->run();
}
