#include "bubble_sort.hpp"
#include "swap.hpp"

void bubble_sort::sort(int arr[], size_t n, comparator& comp)
{
	for (size_t i = 0; i < n-1; i++)
		for (size_t j = 0; j < n-i-1; j++)
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
}
