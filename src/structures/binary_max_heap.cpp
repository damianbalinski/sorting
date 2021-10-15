#include "binary_max_heap.hpp"
#include "swap.hpp"

void binary_max_heap::heap(int arr[], const size_t n, const comparator& comp) const
{
	for (size_t i = n/2; i > 0; i--)
		heapify(arr, n, i-1, comp);
}

void binary_max_heap::heapify(int arr[], const size_t n, const size_t i, const comparator& comp) const
{
	size_t largest = i;
	const size_t left = 2*i + 1;
	const size_t right = 2*i + 2;

	if (left < n && comp.gt(arr[left], arr[largest]))
		largest = left;

	if (right < n && comp.gt(arr[right], arr[largest]))
		largest = right;

	if (largest != i)
	{
		swap(&arr[i], &arr[largest]);
		heapify(arr, n, largest, comp);
	}
}