#include "quick_merge_intro_sort.hpp"
#include "insertion_sort.hpp"
#include "heap_sort.hpp"
#include "merge_sort_by_swaps.hpp"
#include "quick_merge_sort.hpp"
#include "partition_result.hpp"

void quick_merge_intro_sort::sort(int arr[], const size_t n, const size_t depth, const operation& oper) const
{
	if (n <= MAX_LENGTH)
	{
		insertion_sort::sort(arr, n, oper);
		return;
	}

	if (depth == 0)
	{
		heap_sort::sort(arr, n, oper);
		return;
	}

	const partition_result r = (*partition)(arr, n, oper);

	if (r.n1 < r.n2)
	{
		merge_sort_by_swaps::sort(r.arr1, r.arr2, r.n1, oper);
		sort(r.arr2, r.n2, depth-1, oper);
	}
	else
	{
		merge_sort_by_swaps::sort(r.arr2, r.arr1, r.n2, oper);
		sort(r.arr1, r.n1, depth-1, oper);
	}
}
