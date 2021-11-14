#include "median_of_three_pivot_selector.hpp"
#include "median_of_three.hpp"

void median_of_three_pivot_selector::select(int arr[], const size_t n, const  size_t pos, const operation& oper)
{
	const size_t pivot = median_of_three_index(arr, 0, n/2, n-1, oper);
	swap_pivot_in_position(arr, pivot, pos, oper);
}
