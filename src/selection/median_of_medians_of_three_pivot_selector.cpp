#include "median_of_medians_of_three_pivot_selector.hpp"
#include "median_of_three.hpp"
#include "maximum.hpp"

void median_of_medians_of_three_pivot_selector::select(int arr[], const size_t n, const size_t pos, const operation& oper)
{
	const size_t pivot = select_recursively(arr, n, oper);
	swap_pivot_in_position(arr, pivot, pos, oper);
}

size_t median_of_medians_of_three_pivot_selector::select_recursively(int arr[], const size_t n, const operation& oper)
{
	if (n == 1) return 0;
	if (n == 2) return maximum_index(arr, 2, oper);
	if (n == 3) return median_of_three_index(arr, 0, n/2, n-1, oper);

	const size_t i1 = sample(1, n);
	const size_t i2 = sample(2, n);
	return median_of_three_index(arr,
		select_recursively(arr, i1 , oper),
		i1 + select_recursively(arr+i1, i2-i1, oper),
		i2 + select_recursively(arr+i2, n-i2, oper), oper
	);
}
