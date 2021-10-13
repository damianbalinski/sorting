#pragma once
#include "sorting.hpp"
#include "heap.hpp"
#include "binary_max_heap.hpp"

class heap_sort : public sorting
{
public:
	void operator()(int arr[], const size_t n, const comparator& comp) const override { sort(arr, n, comp); }

	static void sort(int arr[], size_t n, const comparator& comp) { sort(arr, n, comp, binary_max_heap()); }

private:
	
	static void sort(int arr[], size_t n, const comparator& comp, const heap& heap);
};
