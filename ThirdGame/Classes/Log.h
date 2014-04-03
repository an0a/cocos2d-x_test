#ifndef __LOG_HEADER__
#define __LOG_HEADER__

#define __F		__FUNCTION__	// 짧게 쓰기 위한 디파인.


// __F 일일이 쓰기 귀찮으니 이렇게..

#ifdef WIN32
extern void LOGN_F( const char* szFunc, const char* szFmt, ... );	// 너무 기니까 얘만 네임스페이스에서 뺀다.

#define LOGN(...) LOGN_F(__FUNCTION__, __VA_ARGS__)

namespace LOG
{
	bool InitAndCreateLogSystem();
	void SetConsolePos( int x, int y );
	void DestroyLogSystem();
}
#else	// 윈도우가 아닐 경우 그냥 printf

#define LOGN	printf

#endif	// for WIN32

#endif