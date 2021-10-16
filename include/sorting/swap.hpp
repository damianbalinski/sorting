#pragma once
#include "operation.hpp"

inline void swap(int* a, int* b)
{
	const int temp = *a;
	*a = *b;
	*b = temp;
}

inline void swap_in_order(int* a, int* b, const operation& oper)
{
	if (oper.gt(*a, *b)) swap(a, b);
}