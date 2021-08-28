#pragma once
#include "sorting.hpp"

class dual_pivot_quick_sort : public sorting
{
public:
	void operator()(int arr[], const size_t n, const comparator& comp) const override { sort(arr, n, comp); }

private:
	static void sort(int arr[], size_t n, const comparator& comp);
};