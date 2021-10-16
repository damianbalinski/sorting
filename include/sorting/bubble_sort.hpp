#pragma once
#include "sorting.hpp"
#include "swapper.hpp"

class bubble_sort: public sorting
{
public:
	void operator()(int arr[], const size_t n, const comparator& comp) const override { sort(arr, n, comp, swapper()); }

	static void sort(int arr[], size_t n, const comparator& comp, const swapper& swapper);
};
