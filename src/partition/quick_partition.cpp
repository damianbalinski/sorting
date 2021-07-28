#include "quick_partition.hpp"
#include "swap.hpp"

size_t quick_partition::partition(int arr[], const size_t n, const comparator& comp)
{
	int pivot = arr[n-1];
	size_t i = 0;

	for (size_t j = 0; j < n; j++)
	{
		if (comp.lt(arr[j], pivot))
		{
			swap(&arr[i], &arr[j]);
			i++;
        }
    }

	swap(&arr[i], &arr[n-1]);
	return i;
}
