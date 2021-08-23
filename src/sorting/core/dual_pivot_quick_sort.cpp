#include "dual_pivot_quick_sort.hpp"
#include "dual_pivot_quick_partition.hpp"

void dual_pivot_quick_sort::sort(int arr[], const size_t n, const comparator& comp)
{
	if (n > 1)
	{
		const size_t* pivots = dual_pivot_quick_partition::partition(arr, n, comp);
		const size_t n1 = pivots[0];
		const size_t n2 = pivots[1] - pivots[0] - 1;
		const size_t n3 = n - pivots[1] - 1;
		
		sort(arr, n1, comp);
		sort(arr+pivots[0]+1, n2, comp);
		sort(arr+pivots[1]+1, n3, comp);
		delete [] pivots;
	}
}
