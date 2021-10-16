#pragma once
#include "heap.hpp"

class binary_max_heap : public heap
{
public:
	void operator()(int arr[], size_t n, const operation& oper) const override { heap(arr, n, oper); }

	void heapify(int arr[], size_t n, size_t i, const operation& oper) const override;

private:
	void heap(int arr[], size_t n, const operation& oper) const;
};
