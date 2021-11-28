#include "dual_pivot_quick_sort.hpp"
#include "dual_pivot_quick_partition.hpp"

void dual_pivot_quick_sort::sort(int arr[], const size_t n, const operation& oper) const
{
	if (n > 1)
	{
		const multi_pivot_partition_result r = (*partition)(arr, n, 2, oper);
		sort(r.arrs[0], r.ns[0], oper);
		sort(r.arrs[1], r.ns[1], oper);
		sort(r.arrs[2], r.ns[2], oper);
	}
}
