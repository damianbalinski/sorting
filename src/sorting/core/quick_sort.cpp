#include "quick_sort.hpp"
#include "partition_result.hpp"

void quick_sort::sort(int arr[], const size_t n, const operation& oper) const
{
    if (n > 1)
    {
        const partition_result r = (*partition)(arr, n, oper);
        sort(r.arr1, r.n1, oper);
    	sort(r.arr2, r.n2, oper);
    }
}
