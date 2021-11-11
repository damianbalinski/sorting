#include "middle_pivot_selector.hpp"

size_t middle_pivot_selector::select(int arr[], const size_t n, const operation& oper)
{
	const size_t pivot = n/2;
	if (pivot != n-1)
		oper.swap(&arr[pivot], &arr[n-1]);
	return n - 1;
}
