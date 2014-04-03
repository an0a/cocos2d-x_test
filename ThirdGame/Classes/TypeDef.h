#pragma once




#ifndef IN
#	define IN
#endif

#ifndef OUT
#	define	OUT
#endif


#ifndef SAFE_DELETE
#define SAFE_DELETE(p)				{ if (p) { delete p; p = NULL; } }
#endif

#ifndef SAFE_DELETE_ARRAY
#define SAFE_DELETE_ARRAY(p)		{ if (p) { delete[] p; p = NULL; } }
#endif

#ifndef SAFE_RELEASE
#define SAFE_RELEASE(p)				{ if (p) { p->Release(); p = NULL; } }
#endif

#ifndef SAFE_DESTROY_AND_DELETE
#define SAFE_DESTROY_AND_DELETE(p)  { if (p) { p->Destroy(); delete p; p = NULL; } }
#endif


// 윈도우가 아닐때만 기본 값들 셋팅해줌.
#ifndef WIN32

#	ifndef BYTE
	typedef unsigned char       BYTE;	
#	endif

#	ifndef WORD
	typedef unsigned short      WORD;
#	endif

#	ifndef DWORD
	typedef unsigned int        DWORD;
#	endif

#	ifndef UINT
	typedef unsigned int        UINT;
#	endif

#	ifndef INT64
	typedef long long           INT64;
#	endif

#	ifndef UINT64
	typedef unsigned long long	UINT64;
#	endif

#endif

#include "Log.h"

