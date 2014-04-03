#ifndef __BASE_VARIABLE_ARGUMENTS_HEADER__
#define __BASE_VARIABLE_ARGUMENTS_HEADER__


//////////////////////////////////////////////////////////////////////////
// 가변인자( sprintf의 ... 등의.. ) 코드를 핸들링 하기위한 코드

//////////////////////////////////////////////////////////////////////////
// 2011-02-08	anoa		작성.
//////////////////////////////////////////////////////////////////////////

// TODO: 이하의 코드가 _s 때문에 맥에선 동작 안하니 추후에 동작 하도록 
//														변경한다.  - anoa

#include <stdarg.h>



#ifdef TARGET_OS_WINDOWS

#define GET_VA_STRING( szBuffer, bufferSize, szFmt, outLen ) \
{\
	va_list va;\
\
	{\
		va_start(va,szFmt);\
		outLen = _vsnprintf_s(szBuffer, bufferSize-1, bufferSize-1, szFmt, va);\
		va_end(va);\
\
		szBuffer[outLen] = 0;\
	}\
}

#else

#define GET_VA_STRING( szBuffer, bufferSize, szFmt, outLen ) \
{\
	va_list va;\
\
	{\
		va_start(va,szFmt);\
		outLen = vsnprintf(szBuffer, bufferSize-1, szFmt, va);\
		va_end(va);\
\
		szBuffer[outLen] = 0;\
	}\
}

#endif

// \n을 붙여서 돌려주는 함수.
#ifdef TARGET_OS_WINDOWS

#define GET_VA_STRING_N( szBuffer, bufferSize, szFmt, outLen ) \
{\
	va_list va;\
\
	{\
		va_start(va,szFmt);\
		size_t retLen = _vsnprintf_s(szBuffer, bufferSize-2, _TRUNCATE, szFmt, va);\
		va_end(va);						\
										\
		if ( retLen != -1 )				\
			outLen = retLen + 1;		\
		else							\
			outLen = bufferSize;		\
										\
		szBuffer[ outLen - 1] = '\n';	\
		szBuffer[ outLen] = 0;			\
	}\
}

#else

#define GET_VA_STRING_N( szBuffer, bufferSize, szFmt, outLen ) \
{\
	va_list va;\
\
	{\
		va_start(va,szFmt);\
		outLen = vsnprintf(szBuffer, bufferSize-2, szFmt, va);\
		va_end(va);\
\
		szBuffer[outLen] = '\n';\
		szBuffer[outLen + 1] = 0;\
		outLen++;	\
	}\
}

#endif


#endif
