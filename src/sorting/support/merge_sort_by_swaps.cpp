#include "merge_sort_by_swaps.hpp"

void merge_sort_by_swaps::sort(int arr[], int buff[], const size_t n, const operation& oper)
{
	if (n > 1)
	{
		const size_t n1 = n / 2;
		const size_t n2 = n - n1;

		sort(arr, buff, n1, oper);
		sort(arr + n1, buff, n2, oper);
		merge(arr, buff, n1, n2, oper);
	}
}

void merge_sort_by_swaps::merge(int arr[], int buff[], const size_t n1, const size_t n2, const operation& oper)
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
		oper.arr_swap(arr + k, left + i, n1 - i);
}
