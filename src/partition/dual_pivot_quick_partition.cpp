#include "dual_pivot_quick_partition.hpp"
#include "array_utils.hpp"
#include "swap.hpp"

const size_t* dual_pivot_quick_partition::partition(int arr[], const size_t n, const comparator& comp)
{
	const size_t left_pivot_pos = 0;
	const size_t right_pivot_pos = n-1;

	swap_in_order(&arr[left_pivot_pos], &arr[right_pivot_pos], comp);
	const int left_pivot = arr[left_pivot_pos];
	const int right_pivot = arr[right_pivot_pos];
	
	size_t i = left_pivot_pos + 1;
	size_t j = right_pivot_pos - 1;
	size_t k = i;

	while (k <= j)
	{
		if (comp.lt(arr[k], left_pivot))
		{
			swap(&arr[k++], &arr[i++]);
		}
		else if (comp.ge(arr[k], right_pivot))
		{
			while (comp.gt(arr[j], right_pivot) && k < j) j--;
			swap(&arr[k], &arr[j--]);
		}
		else
		{
			k++;
		}
	}

	i--;
	j++;
	swap(&arr[left_pivot_pos], &arr[i]);
	swap(&arr[right_pivot_pos], &arr[j]);
	return arr_from(i, j);
}
