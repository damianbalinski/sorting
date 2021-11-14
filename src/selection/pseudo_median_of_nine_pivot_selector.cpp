#include "pseudo_median_of_nine_pivot_selector.hpp"
#include "median_of_three.hpp"

size_t pseudo_median_of_nine_pivot_selector::select(int arr[], const size_t n, const operation& oper)
{
	const size_t pivot = median_of_three_index(arr,
		median_of_three_index(arr, pos(0, n), pos(1, n), pos(2, n), oper),
		median_of_three_index(arr, pos(3, n), pos(4, n), pos(5, n), oper),
		median_of_three_index(arr, pos(6, n), pos(7, n), pos(8, n), oper), oper
	);

	if (pivot != n - 1)
		oper.swap(&arr[pivot], &arr[n - 1]);
	return n - 1;
}
