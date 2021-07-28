#include "minimum.hpp"
#include "assert.hpp"

int minimum(int* const arr, const size_t n, const comparator& comp)
{
    check_num_greater_than_zero(n);
	int min = arr[0];
	
    for (size_t i = 1; i < n; i++)
    {
        if (comp.lt(arr[i], min))
            min = arr[i];
    }
	return min;
}

size_t minimum_index(int* const arr, const size_t n, const comparator& comp)
{
    check_num_greater_than_zero(n);
    size_t min = 0;
	
    for (size_t i = 1; i < n; i++)
    {
        if (comp.lt(arr[i], arr[min]))
            min = i;
    }
    return min;
}
