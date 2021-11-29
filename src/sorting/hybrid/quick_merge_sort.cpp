#include "quick_merge_sort.hpp"
#include "merge_sort_by_swaps.hpp"
#include "partition_result.hpp"

void quick_merge_sort::sort(int arr[], const size_t n, const operation& oper) const
{
	
	if (n > 1)
	{
		const partition_result r = (*partition)(arr, n, oper);

		if (r.n1 < r.n2)
		{
			merge_sort_by_swaps::sort(r.arr1, r.arr2, r.n1, oper);
			sort(r.arr2, r.n2, oper);
		}
		else
		{
			merge_sort_by_swaps::sort(r.arr2, r.arr1, r.n2, oper);
			sort(r.arr1, r.n1, oper);
		}
	}
}
