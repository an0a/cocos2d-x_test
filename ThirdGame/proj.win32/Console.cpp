#include "stdafx.h"
#include "Console.h"

#include <io.h>
#include <fcntl.h>


void CConsole::Init()
{
	m_hConsole	= INVALID_HANDLE_VALUE;
}

bool CConsole::Create( int posX, int posY )
{
	::AllocConsole();


	int consoleHandle = _open_osfhandle((long)GetStdHandle(STD_OUTPUT_HANDLE), _O_TEXT);

	if ( consoleHandle == -1 )
		return false;

	FILE* fileHandle = _fdopen( consoleHandle, "w" );

	if ( fileHandle == NULL )
		return false;

	*stdout = *fileHandle;
	if ( setvbuf(stdout, NULL, _IONBF, 0) != 0 )
		return false;

	//////////////////////////////////////////////////////////////////////////

	m_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetStdHandle( STD_ERROR_HANDLE, (HANDLE)m_hConsole );

	SetConsolePos( posX, posY );

	return true;
}

void CConsole::Destroy()
{
	if ( m_hConsole != INVALID_HANDLE_VALUE )
	{
		m_hConsole	= INVALID_HANDLE_VALUE;
		::FreeConsole();
	}
}

void CConsole::SetColor( UINT colorType )
{
	assert( colorType < COLOR_MAX_NUM );


	switch( colorType )
	{
		case COLOR_DEBUG:
			::SetConsoleTextAttribute( m_hConsole, FOREGROUND_INTENSITY );
			break;

		case COLOR_INFO:
			::SetConsoleTextAttribute( m_hConsole, ( BACKGROUND_BLUE | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY));
			break;

		case COLOR_ERROR:
			::SetConsoleTextAttribute( m_hConsole, BACKGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY  );
			break;

		case COLOR_WARNING:
			::SetConsoleTextAttribute( m_hConsole, BACKGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY  );
			break;
			
		default:
			printf( "#   no handling colorType(%d)\n", colorType );
			break;
	}
}

void CConsole::SetConsolePos( int x, int y )
{
	HWND hWnd = GetConsoleWindow();	

	WINDOWPLACEMENT	place;
	GetWindowPlacement( hWnd, &place );

	RECT& rRect = place.rcNormalPosition;

	rRect.right		= rRect.right - rRect.left + x;
	rRect.left		= x;

	rRect.bottom	= rRect.bottom - rRect.top + y;
	rRect.top		= y;

		//		place.showCmd	= SW_SHOWMAXIMIZED;
	SetWindowPlacement( hWnd, &place );
	//		SetWindowPos( hWnd, NULL, 0, 0, 100,100, NULL );

}

void CConsole::WriteText( const char* szText, size_t textLen )
{
	WriteConsole( m_hConsole, szText, textLen, NULL, NULL );
}


