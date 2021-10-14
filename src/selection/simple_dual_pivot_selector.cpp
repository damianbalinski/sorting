#include "simple_dual_pivot_selector.hpp"
#include "array_utils.hpp"
#include "swap.hpp"

size_t* simple_dual_pivot_selector::select(int arr[], const size_t n, const comparator& comp)
{
	swap_in_order(&arr[0], &arr[n-1], comp);
	return arr_from(0, n-1);
}
