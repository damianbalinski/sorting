#pragma once
#include "sorting.hpp"

class insertion_sort : public sorting
{
public:
	void operator()(int arr[], const size_t n, const comparator& comp) const override { sort(arr, n, comp); }

	static void sort(int arr[], size_t n, const comparator& comp);
};
