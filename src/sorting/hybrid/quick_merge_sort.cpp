#include "quick_merge_sort.hpp"
#include "partition_result.hpp"

void quick_merge_sort::sort(int arr[], const size_t n, const operation& oper) const
{
	
	if (n > 1)
	{
		const partition_result r = (*partition)(arr, n, oper);

		if (r.n1 < r.n2)
		{
			merge_sort_by_swaps(r.arr1, r.arr2, r.n1, oper);
			sort(r.arr2, r.n2, oper);
		}
		else
		{
			merge_sort_by_swaps(r.arr2, r.arr1, r.n2, oper);
			sort(r.arr1, r.n1, oper);
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
	oper.arr_swap(buff, arr, n1);
	int* left = buff;
	int* right = arr + n1;

	size_t i, j, k;
	i = j = k = 0;

	while (i < n1 && j < n2)
	{
		if (oper.lt(left[i], right[j]))
			oper.swap(&arr[k++], &left[i++]);
		else
			oper.swap(&arr[k++], &right[j++]);
	}

	if (i < n1)
		oper.arr_swap(arr+k, left+i, n1-i);
}
