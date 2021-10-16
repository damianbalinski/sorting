#include "quick_partition.hpp"
#include "simple_pivot_selector.hpp"
#include "swap.hpp"

const pivot_selector& quick_partition::DEFAULT_PIVOT_SELECTOR = simple_pivot_selector{};

size_t quick_partition::partition(int arr[], const size_t n, const operation& oper, const pivot_selector& pivot_selector)
{
	const size_t pivot_index = pivot_selector(arr, n, oper);
	int pivot = arr[pivot_index];
	size_t i = 0;

	for (size_t j = 0; j < n; j++)
	{
		if (oper.lt(arr[j], pivot))
		{
			swap(&arr[i], &arr[j]);
			i++;
        }
    }

	swap(&arr[i], &arr[pivot_index]);
	return i;
}
