#pragma once
#include "sorting.hpp"

class quick_merge_sort : public sorting
{
public:
	void operator()(int arr[], const size_t n, const comparator& comp) const override { sort(arr, n, comp); }

private:
	static void sort(int arr[], size_t n, const comparator& comp);

	static void merge_sort_by_swaps(int arr[], int buff[], size_t n, const comparator& comp);
	
	static void merge_by_swaps(int arr[], int buff[], size_t n1, size_t n2, const comparator& comp);
};
