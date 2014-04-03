#ifndef __LOG_HEADER__
#define __LOG_HEADER__

#define __F		__FUNCTION__	// ª�� ���� ���� ������.


// __F ������ ���� �������� �̷���..

#ifdef WIN32
extern void LOGN_F( const char* szFunc, const char* szFmt, ... );	// �ʹ� ��ϱ� �길 ���ӽ����̽����� ����.

#define LOGN(...) LOGN_F(__FUNCTION__, __VA_ARGS__)

namespace LOG
{
	bool InitAndCreateLogSystem();
	void SetConsolePos( int x, int y );
	void DestroyLogSystem();
}
#else	// �����찡 �ƴ� ��� �׳� printf

#define LOGN	printf

#endif	// for WIN32

#endif