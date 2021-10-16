#include "median_of_three_pivot_selector.hpp"
#include "median_of_three.hpp"
#include "swap.hpp"

size_t median_of_three_pivot_selector::select(int arr[], const size_t n, const operation& oper)
{
	const size_t pivot = median_of_three_index(arr, n, oper);
	if (pivot != n-1)
		swap(&arr[pivot], &arr[n-1]);
	return n-1;
}
