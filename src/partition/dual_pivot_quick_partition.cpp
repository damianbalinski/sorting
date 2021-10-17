#include "dual_pivot_quick_partition.hpp"
#include "simple_dual_pivot_selector.hpp"
#include "array_utils.hpp"

const multi_pivot_selector& dual_pivot_quick_partition::DEFAULT_DUAL_PIVOT_SELECTOR = simple_dual_pivot_selector{};

size_t* dual_pivot_quick_partition::partition(int arr[], const size_t n, const operation& oper, const multi_pivot_selector& multi_pivot_selector)
{
	const size_t* pivots = multi_pivot_selector(arr, n, 2, oper);
	const size_t left_index = pivots[0];
	const size_t right_index = pivots[1];
	delete [] pivots;
	
	const int left_pivot = oper.assign(arr[left_index]);
	const int right_pivot = oper.assign(arr[right_index]);
	
	size_t i = left_index + 1;
	size_t j = right_index - 1;
	size_t k = i;

	while (k <= j)
	{
		if (oper.lt(arr[k], left_pivot))
		{
			oper.swap(&arr[k++], &arr[i++]);
		}
		else if (oper.ge(arr[k], right_pivot))
		{
			while (oper.gt(arr[j], right_pivot) && k < j) j--;
			oper.swap(&arr[k], &arr[j--]);
		}
		else
		{
			k++;
		}
	}

	i--;
	j++;
	oper.swap(&arr[left_index], &arr[i]);
	oper.swap(&arr[right_index], &arr[j]);
	return arr_from(i, j);
}
