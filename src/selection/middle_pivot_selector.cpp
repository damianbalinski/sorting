#include "middle_pivot_selector.hpp"

void middle_pivot_selector::select(int arr[], const size_t n, const size_t pos, const operation& oper)
{
	const size_t pivot = n/2;
	swap_pivot_in_position(arr, pivot, pos, oper);
}
