#include "merge_sort.hpp"
#include "array_utils.hpp"

void merge_sort::sort(int arr[], const size_t n, const operation& oper)
{
	if (n > 1)
	{
		const size_t n1 = n / 2;
		const size_t n2 = n - n1;
		
		sort(arr, n1, oper);
		sort(arr+n1, n2, oper);

		int* buff = new int[n1];
		merge(arr, buff, n1, n2, oper);
		delete [] buff;
	}
}

void merge_sort::merge(int arr[], int buff[], const size_t n1, const size_t n2, const operation& oper)
{
	const int* const left = oper.arr_copy(buff, arr, n1);
	const int* const right = arr + n1;

	size_t i, j, k;
	i = j = k = 0;

	while (i < n1 && j < n2)
	{
		if (oper.lt(left[i], right[j]))
			arr[k++] = oper.assign(left[i++]);
		else
			arr[k++] = oper.assign(right[j++]);
	}

	if (i < n1)
		oper.arr_copy(arr+k, left+i, n1-i);
}
