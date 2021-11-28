#include "selection_sort.hpp"
#include "maximum.hpp"

void selection_sort::sort(int arr[], const size_t n, const operation& oper)
{
    for (size_t i = n; i > 1; i--)
    {
        const size_t max = maximum_index(arr, i, oper);
        oper.swap(&arr[i-1], &arr[max]);
    }
}
