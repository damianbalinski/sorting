#include "lemuto_partition.hpp"

size_t lemuto_partition::partitione(int arr[], const size_t n, const operation& oper) const
{
	const size_t pivot_index = (*selector)(arr, n, oper);
	const int pivot = oper.assign(arr[pivot_index]);
	size_t i = 0;

	for (size_t j = 0; j < n; j++)
	{
		if (oper.lt(arr[j], pivot))
		{
			oper.swap(&arr[i], &arr[j]);
			i++;
        }
    }

	oper.swap(&arr[i], &arr[pivot_index]);
	return i;
}
