#include "quick_merge_sort.hpp"
#include "quick_partition.hpp"
#include "simple_pivot_selector.hpp"
#include "array_utils.hpp"
#include "swap.hpp"

void quick_merge_sort::sort(int arr[], const size_t n, const operation& oper)
{
	
	if (n > 1)
	{
		const size_t pivot = quick_partition::partition(arr, n, oper, simple_pivot_selector());
		const size_t n1 = pivot;
		const size_t n2 = n - pivot - 1;

		if (n1 < n2)
		{
			merge_sort_by_swaps(arr, arr+pivot+1, n1, oper);
			sort(arr+pivot+1, n2, oper);
		}
		else
		{
			merge_sort_by_swaps(arr+pivot+1, arr, n2, oper);
			sort(arr, n1, oper);
		}
	}
}

void quick_merge_sort::merge_sort_by_swaps(int arr[], int buff[], const size_t n, const operation& oper)
{
	if (n > 1)
	{
		const size_t n1 = n / 2;
		const size_t n2 = n - n1;

		merge_sort_by_swaps(arr, buff, n1, oper);
		merge_sort_by_swaps(arr + n1, buff, n2, oper);
		merge_by_swaps(arr, buff, n1, n2, oper);
	}
}

void quick_merge_sort::merge_by_swaps(int arr[], int buff[], const size_t n1, const size_t n2, const operation& oper)
{
	int* left = arr_swap(buff, arr, n1);
	int* right = arr + n1;

	size_t i, j, k;
	i = j = k = 0;

	while (i < n1 && j < n2)
	{
		if (oper.lt(left[i], right[j]))
			swap(&arr[k++], &left[i++]);
		else
			swap(&arr[k++], &right[j++]);
	}

	if (i < n1)
		arr_swap(arr + k, left + i, n1 - i);
}
