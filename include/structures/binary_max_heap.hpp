#pragma once
#include "heap.hpp"

class binary_max_heap : public heap
{
public:
	void operator()(int arr[], size_t n, const comparator& comp) const override { heap(arr, n, comp); }

	void heapify(int arr[], size_t n, size_t i, const comparator& comp) const override;

private:
	void heap(int arr[], size_t n, const comparator& comp) const;
};
