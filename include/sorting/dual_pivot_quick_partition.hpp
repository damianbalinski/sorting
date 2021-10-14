#pragma once
#include "multi_pivot_partition.hpp"
#include "multi_pivot_selector.hpp"

class dual_pivot_quick_partition: public multi_pivot_partition
{
public:
	size_t* operator()(int arr[], size_t n, size_t number_of_pivots, const comparator& comp) const override { return partition(arr, n, comp, DEFAULT_DUAL_PIVOT_SELECTOR); }

	static size_t* partition(int arr[], size_t n, const comparator& comp, const multi_pivot_selector& multi_pivot_selector);

private:
	const static multi_pivot_selector& DEFAULT_DUAL_PIVOT_SELECTOR;
};
