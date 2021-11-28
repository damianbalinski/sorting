#include "bubble_sort.hpp"

void bubble_sort::sort(int arr[], const size_t n, const operation& oper)
{
	for (size_t i = 0; i < n-1; i++)
		for (size_t j = 0; j < n-i-1; j++)
			if (oper.gt(arr[j],arr[j+1]))
				oper.swap(&arr[j], &arr[j+1]);
}
