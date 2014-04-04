#ifndef __BASE_STL_HEADER__
#define __BASE_STL_HEADER__


#include <vector>
#include <list>
#include <string>
#include <set>
#include <map>
#include <algorithm>
//#include <hash_map>


using namespace std;



template<typename T>	// 깔끔히 메모리 날려주기.	 다시 재사용 안 할꺼면 doNotReuse
void ClearVector(T& v, bool doNotReuse = false )
{
	if (!v.empty())
		v.clear();

	T tmp;
	tmp.swap( v );

	/*
    // Don't do this for xcode
	v.~T();	

	if ( !doNotReuse )
		new ( &v ) T();
	*/
}

inline void ToUpper(string & rString)
{
	for (string::iterator i = rString.begin(); i != rString.end(); ++i)
	{
		*i = (char)::toupper(*i);
	}
}

inline void ToLower(string & rString)
{
	for (string::iterator i = rString.begin(); i != rString.end(); ++i)
	{
		*i = (char)::tolower(*i);
	}
}

#ifndef FIND_ITERATOR
#define FIND_ITERATOR( cont_type, cont_instance, findValue, iterator_name )						\
	cont_type::iterator iterator_name = (cont_instance).end();									\
																								\
	for ( cont_type::iterator itr = (cont_instance).begin(), itrEnd = (cont_instance).end();	\
		itr != itrEnd; ++itr )																	\
	{																							\
		if ( *itr == findValue )																\
		{																						\
			iterator_name	= itr;																\
			break;																				\
		}																						\
	}
#endif

#ifndef FIND_CONST_ITERATOR
#define FIND_CONST_ITERATOR( cont_type, cont_instance, findValue, iterator_name )			\
	cont_type::const_iterator iterator_name = (cont_instance).end();								\
																									\
	for ( cont_type::const_iterator itr = (cont_instance).begin(), itrEnd = (cont_instance).end();	\
	itr != itrEnd; ++itr )																			\
	{																								\
		if ( *itr == findValue )																	\
		{																							\
			iterator_name	= itr;																	\
			break;																					\
		}																							\
	}
#endif


#define IF_FIND_ITERATOR( cont_type, cont_instance, findValue, iterator_name )			\
	FIND_ITERATOR( cont_type, cont_instance, findValue, iterator_name );				\
	if ( iterator_name != cont_instance.end())

#define IF_FIND_CONST_ITERATOR( cont_type, cont_instance, findValue, iterator_name )		\
	FIND_CONST_ITERATOR( cont_type, cont_instance, findValue, iterator_name );			\
	if ( iterator_name != cont_instance.end())



// 특정 번쨰의 이터레이터 리턴해주기
#ifndef GET_ITERATOR
#define GET_ITERATOR( cont_type, cont_instance, num, iterator_name )				\
	cont_type::iterator iterator_name = cont_instance.begin();								\
	for ( int ___i=0;___i<(int)num;___i++) iterator_name++;
#endif

#ifndef GET_CONST_ITERATOR
#define GET_CONST_ITERATOR( cont_type, cont_instance, num, iterator_name )				\
	cont_type::const_iterator iterator_name = cont_instance.begin();								\
	for ( int ___i=0;___i<(int)num;___i++) iterator_name++;
#endif



/// 컨테이너 돌려주기..
#ifndef FOR_EACH_CONT
#define FOR_EACH_CONT( cont_type, cont_instance, iterator_name )										\
	for ( cont_type::iterator iterator_name = (cont_instance).begin(), itrEnd = (cont_instance).end();	\
	iterator_name != itrEnd; ++iterator_name )
#endif//FOR_EACH_CONT

#ifndef FOR_EACH_CONST_CONT
#define FOR_EACH_CONST_CONT( cont_type, cont_instance, iterator_name )										\
	for ( cont_type::const_iterator iterator_name = (cont_instance).begin(), itrEnd = (cont_instance).end();	\
	iterator_name != itrEnd; ++iterator_name )
#endif//FOR_EACH_CONST_CONT


#ifndef REVERSE_FOR_EACH_CONT
#define REVERSE_FOR_EACH_CONT( cont_type, cont_instance, iterator_name )										\
	for ( cont_type::reverse_iterator iterator_name = (cont_instance).rbegin(), itrEnd = (cont_instance).rend();	\
	iterator_name != itrEnd; ++iterator_name )
#endif//FOR_EACH_CONT

#ifndef REVERSE_FOR_EACH_CONST_CONT
#define REVERSE_FOR_EACH_CONST_CONT( cont_type, cont_instance, iterator_name )										\
	for ( cont_type::const_reverse_iterator iterator_name = (cont_instance).rbegin(), itrEnd = (cont_instance).rend();	\
	iterator_name != itrEnd; ++iterator_name )
#endif//FOR_EACH_CONT


#endif


