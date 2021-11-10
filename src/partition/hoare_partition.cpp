#include "hoare_partition.hpp"

size_t hoare_partition::partitione(int arr[], const size_t n, const operation& oper) const
{
 const int pivot = arr[(n-1)/2];

    long long i = -1, j = n;
    while (true)
    {
        do { i++; } while (arr[i] < pivot);
        do { j--; } while (arr[j] > pivot);
        if (i >= j) return j;
        oper.swap(&arr[i], &arr[j]);
    }
}
