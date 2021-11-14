#include "hoare_partition.hpp"

partition_result hoare_partition::partitione(int arr[], const size_t n, const operation& oper) const
{
    const size_t pivot_index = (n-1) / 2;
    (*selector)(arr, n, pivot_index, oper);
	const int pivot = oper.assign(arr[pivot_index]);

    long long i = -1, j = n;
    while (true)
    {
        do { i++; } while (oper.lt(arr[i], pivot));
        do { j--; } while (oper.gt(arr[j], pivot));
        if (i >= j) return prepare_partition_result(arr, n, j);
        oper.swap(&arr[i], &arr[j]);
    }
}

partition_result hoare_partition::prepare_partition_result(int arr[], const size_t n, const size_t pivot)
{
    return partition_result{
        pivot,
        pivot+1,
        n-(pivot+1),
        arr,
        arr+(pivot+1)
    };
}
