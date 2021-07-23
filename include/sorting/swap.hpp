#pragma once

inline void swap(int* a, int* b)
{
	const int temp = *a;
	*a = *b;
	*b = temp;
}
