#include "pseudo_median_of_nine_pivot_selector.hpp"
#include "median_of_three.hpp"

void pseudo_median_of_nine_pivot_selector::select(int arr[], const size_t n, const size_t pos, const operation& oper)
{
	const size_t pivot = median_of_three_index(arr,
		median_of_three_index(arr, sample(0, n), sample(1, n), sample(2, n), oper),
		median_of_three_index(arr, sample(3, n), sample(4, n), sample(5, n), oper),
		median_of_three_index(arr, sample(6, n), sample(7, n), sample(8, n), oper), oper
	);
	swap_pivot_in_position(arr, pivot, pos, oper);
}
