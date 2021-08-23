#pragma once
#include "comparator.hpp"
#include "multi_pivot_partition.hpp"

class dual_pivot_quick_partition: public multi_pivot_partition
{
public:
	const size_t* operator()(int arr[], size_t n, size_t number_of_pivots, const comparator& comp) const override { return partition(arr, n, comp); }

	static const size_t* partition(int arr[], size_t n, const comparator& comp);
};
