#include "lomuto_partition.hpp"

partition_result lomuto_partition::partitione(int arr[], const size_t n, const operation& oper) const
{
	const size_t pivot_index = n-1;
	(*selector)(arr, n, pivot_index, oper);
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
	return prepare_partition_result(arr, n, i);
}

partition_result lomuto_partition::prepare_partition_result(int arr[], const size_t n, const size_t pivot)
{
	return partition_result{
		pivot,
		pivot,
		n-(pivot+1),
		arr,
		arr+(pivot+1)
	};
}