#include "stdafx.h"
#include "VariableArguments.h"

//#include "PlatformLib/Console.h"

#include "../Proj.win32/Console.h"


#ifdef WIN32

namespace LOG
{
	CConsole* s_pConsole = NULL;

	UINT		s_lastLogColor	= CConsole::COLOR_MAX_NUM;
	extern void ApplyTextColor( char firstLogChar );
}

bool LOG::InitAndCreateLogSystem()
{
	s_pConsole = new CConsole;

	s_pConsole->Init();

	if ( !s_pConsole->Create( 0, 650 ))
		return false;
	
	return true;
}

void LOG::SetConsolePos( int x, int y )
{
	s_pConsole->SetConsolePos( x, y );
}

void LOG::DestroyLogSystem()
{
	SAFE_DESTROY_AND_DELETE( s_pConsole ); 
}

void LOG::ApplyTextColor( char firstLogChar )
{
	UINT logColor = CConsole::COLOR_DEBUG;

	if ( firstLogChar == '#' )
		logColor = CConsole::COLOR_ERROR;
	else if( firstLogChar == '!' )
		logColor = CConsole::COLOR_WARNING;
	else if( firstLogChar == '*' )
		logColor = CConsole::COLOR_INFO;

	if ( logColor == s_lastLogColor )
		return;

	s_lastLogColor	= logColor;
	LOG::s_pConsole->SetColor( s_lastLogColor );	
}


void LOGN_F( const char* szFunc, const char* szFmt, ... )
{
	if ( !LOG::s_pConsole )
		return;

#ifdef _DEBUG
	char szBuf[1024 * 10];
#else
	char szBuf[2048];
#endif

	size_t funcLen	= strlen( szFunc );

	if ( funcLen > 0 )
		funcLen += 2;		// +2 = function] 까지 포함한 싸이즈.

	size_t bufLen	= sizeof( szBuf ) - funcLen;
	char* p			= szBuf + funcLen;

	if ( funcLen > 0 )
	{
		assert( sizeof( szBuf ) > funcLen );
	

		{	// 앞에 function 붙여주고..
			memcpy( szBuf, szFunc, funcLen );
			szBuf[ funcLen-2 ] = ']';
			szBuf[ funcLen-1 ] = ' ';
		}
	}

	//////////////////////////////////////////////////////////////////////////

	/*
	{
		va_list va;

		{
			va_start(va,szFmt);
			size_t retLen = _vsnprintf_s( p, bufLen-2, _TRUNCATE, szFmt, va );
			va_end(va);
		
			if ( retLen != -1 )
				bufLen = retLen+1;
			else
				bufLen = bufLen;
		
			p[ bufLen - 1] = '\n';
			p[ bufLen ] = 0;
		}
	}
	*/
	//////////////////////////////////////////////////////////////////////////

	GET_VA_STRING_N( p, bufLen, szFmt, bufLen );

	if ( !LOG::s_pConsole )
	{
		printf( "%s", szBuf );
		return;
	}

	LOG::ApplyTextColor( *szFmt );

	LOG::s_pConsole->WriteText( szBuf, bufLen + funcLen );
}


#endif