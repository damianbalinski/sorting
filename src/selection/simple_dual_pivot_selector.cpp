#include "simple_dual_pivot_selector.hpp"
#include "array_utils.hpp"

size_t* simple_dual_pivot_selector::select(int arr[], const size_t n, const operation& oper)
{
	oper.swap_in_order(&arr[0], &arr[n-1]);
	return arr_from(0, n-1);
}
