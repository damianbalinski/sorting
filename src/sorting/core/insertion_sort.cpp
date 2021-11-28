#include "insertion_sort.hpp"

void insertion_sort::sort(int arr[], const size_t n, const operation& oper)
{
    for (size_t i = 1; i < n; i++)
    {
        const int key = oper.assign(arr[i]);
        size_t j = i;

        while (j >= 1 && oper.gt(arr[j-1], key))
        {
            arr[j] = oper.assign(arr[j-1]);
            j--;
        }

        arr[j] = oper.assign(key);
    }
}
