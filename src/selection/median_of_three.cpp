#include "median_of_three.hpp"

int median_of_three(int arr[], const size_t ax, const size_t bx, const size_t  cx, const operation& oper)
{
	const int a = arr[ax];
	const int c = arr[bx];
	const int b = arr[cx];

	if (oper.gt(a,b) ^ oper.gt(a,c)) return a;
	if (oper.lt(b,a) ^ oper.lt(b,c)) return b;
	return c;
}

size_t median_of_three_index(int arr[], const size_t ax, const size_t bx, const size_t cx, const operation& oper)
{
	const int a = arr[ax];
	const int b = arr[bx];
	const int c = arr[cx];

	if (oper.gt(a, b) ^ oper.gt(a, c)) return ax;
	if (oper.lt(b, a) ^ oper.lt(b, c)) return bx;
	return cx;
}
