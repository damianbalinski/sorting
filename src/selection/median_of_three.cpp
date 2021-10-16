#include "median_of_three.hpp"
#include "numeric_utils.hpp"

int median_of_three(const int* const arr, const size_t n, const operation& oper)
{
	const int a = arr[0];
	const int c = arr[n-1];
	const int b = arr[safe_mean_of_two(0, n-1)];

	if (oper.gt(a,b) ^ oper.gt(a,c)) return a;
	if (oper.lt(b,a) ^ oper.lt(b,c)) return b;
	return c;
}

size_t median_of_three_index(const int* const arr, const size_t n, const operation& oper)
{
	const size_t a_index = 0;
	const size_t c_index = n-1;
	const size_t b_index = safe_mean_of_two(a_index, c_index);
	
	const int a = arr[a_index];
	const int b = arr[b_index];
	const int c = arr[c_index];

	if (oper.gt(a, b) ^ oper.gt(a, c)) return a_index;
	if (oper.lt(b, a) ^ oper.lt(b, c)) return b_index;
	return c_index;
}
