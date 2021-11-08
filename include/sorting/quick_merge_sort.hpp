#pragma once
#include "sorting.hpp"
#include "partition.hpp"

class quick_merge_sort : public sorting
{
public:
	quick_merge_sort(const partition* const partition) : partition(partition) {}

	const char* name() const override { return "quick_merge_sort"; }

	void operator()(int arr[], const size_t n, const operation& oper) const override { sort(arr, n, oper); }

private:
	const partition* const partition;

	void sort(int arr[], size_t n, const operation& oper) const;

	static void merge_sort_by_swaps(int arr[], int buff[], size_t n, const operation& oper);
	
	static void merge_by_swaps(int arr[], int buff[], size_t n1, size_t n2, const operation& oper);
};
