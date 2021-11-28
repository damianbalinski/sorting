#include "heap_sort.hpp"

void heap_sort::sort(int arr[], const size_t n, const operation& oper, const heap& heap)
{
	heap(arr, n, oper);

	for (size_t i = n; i > 0; i--)
	{
		oper.swap(&arr[0], &arr[i-1]);
		heap.heapify(arr, i-1, 0, oper);
	}
}
