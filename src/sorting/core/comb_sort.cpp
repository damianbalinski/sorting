#include "comb_sort.hpp"
#include "bubble_sort.hpp"

void comb_sort::sort(int arr[], const size_t n, const operation& oper, const gapper& gapper)
{
	for (size_t gap = gapper(n); gap > 0; gap = gapper(gap))
		for (size_t i = 0; i < n-gap; i++)
			if (arr[i] > arr[i+gap])
				oper.swap(&arr[i], &arr[i+gap]);

	bubble_sort::sort(arr, n, oper);
}
