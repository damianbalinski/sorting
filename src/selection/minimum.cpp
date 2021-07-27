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

size_t minimum_index_of_partial(int* const arr, const size_t begin, const size_t end, const comparator& comp)
{
    check_num_greater_than_other(end, begin);
    size_t min = begin;
	
    for (size_t i = begin+1; i < end; i++)
    {
        if (comp.lt(arr[i], arr[min]))
            min = i;
    }
    return min;
}
