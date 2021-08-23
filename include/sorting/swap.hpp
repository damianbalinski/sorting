#pragma once
#include "comparator.hpp"

inline void swap(int* a, int* b)
{
	const int temp = *a;
	*a = *b;
	*b = temp;
}

inline void swap_in_order(int* a, int* b, const comparator& comp)
{
	if (comp.gt(*a, *b)) swap(a, b);
}