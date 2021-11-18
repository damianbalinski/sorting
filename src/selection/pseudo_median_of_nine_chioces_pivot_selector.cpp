#include "pseudo_median_of_nine_choices_pivot_selector.hpp"
#include "randomized_median_of_three.hpp"
#include "median_of_three.hpp"

void pseudo_median_of_nine_choices_pivot_selector::select(int arr[], const size_t n, const size_t pos, const operation& oper)
{
	const size_t pivot = median_of_three_index(arr,
		randomized_median_of_three_index(arr, n, oper),
		randomized_median_of_three_index(arr, n, oper),
		randomized_median_of_three_index(arr, n, oper), oper
	);
	swap_pivot_in_position(arr, pivot, pos, oper);
}
