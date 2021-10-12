#include "median_of_three.hpp"

inline size_t safe_mean_of_two(const size_t a, const size_t b)
{
	return a + (b-a)/2;
}

int median_of_three(const int* const arr, const size_t n, const comparator& comp)
{
	const int a = arr[0];
	const int c = arr[n-1];
	const int b = arr[safe_mean_of_two(0, n-1)];

	if (comp.gt(a,b) ^ comp.gt(a,c)) return a;
	if (comp.lt(b,a) ^ comp.lt(b,c)) return b;
	return c;
}

size_t median_of_three_index(const int* const arr, const size_t n, const comparator& comp)
{
	const size_t a_index = 0;
	const size_t c_index = n-1;
	const size_t b_index = safe_mean_of_two(a_index, c_index);
	
	const int a = arr[a_index];
	const int b = arr[b_index];
	const int c = arr[c_index];

	if (comp.gt(a, b) ^ comp.gt(a, c)) return a_index;
	if (comp.lt(b, a) ^ comp.lt(b, c)) return b_index;
	return c_index;
}