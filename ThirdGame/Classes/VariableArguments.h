#ifndef __BASE_VARIABLE_ARGUMENTS_HEADER__
#define __BASE_VARIABLE_ARGUMENTS_HEADER__


//////////////////////////////////////////////////////////////////////////
// ��������( sprintf�� ... ����.. ) �ڵ带 �ڵ鸵 �ϱ����� �ڵ�

//////////////////////////////////////////////////////////////////////////
// 2011-02-08	anoa		�ۼ�.
//////////////////////////////////////////////////////////////////////////

// TODO: ������ �ڵ尡 _s ������ �ƿ��� ���� ���ϴ� ���Ŀ� ���� �ϵ��� 
//														�����Ѵ�.  - anoa

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

// \n�� �ٿ��� �����ִ� �Լ�.
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
