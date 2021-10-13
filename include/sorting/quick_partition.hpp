#pragma once
#include "partition.hpp"
#include "pivot_selector.hpp"
#include "simple_pivot_selector.hpp"

class quick_partition: public partition
{
public:
	size_t operator()(int arr[], const size_t n, const comparator& comp) const override { return partition(arr, n, comp, DEFAULT_PIVOT_SELECTOR); }

	static size_t partition(int arr[], size_t n, const comparator& comp, const pivot_selector& pivot_selector);

private:
	const static pivot_selector& DEFAULT_PIVOT_SELECTOR;
};
