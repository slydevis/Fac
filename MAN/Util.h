#ifndef __UTIL_H__
#define __UTIL_H__

inline void swap(int* a, int* b)
{
	int buff = *a;
	*a = *b;
	*b = buff;
}

#endif
