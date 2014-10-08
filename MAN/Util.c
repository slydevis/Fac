#include "Util.h"

inline void swap(int* a, int* b)
{
	int buff = *a;
	*a = *b;
	*b = buff;
}
