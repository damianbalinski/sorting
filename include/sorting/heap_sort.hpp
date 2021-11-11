#pragma once
#include "sorting.hpp"
#include "heap.hpp"
#include "binary_max_heap.hpp"

class heap_sort : public sorting
{
public:
	const char* name() const override { return "heap_sort"; }

	void operator()(int arr[], const size_t n, const operation& oper) const override { sort(arr, n, oper); }

	static void sort(int arr[], size_t n, const operation& oper) { sort(arr, n, oper, binary_max_heap()); }

private:
	static void sort(int arr[], size_t n, const operation& oper, const heap& heap);
};
