#pragma once
#include "partition.hpp"

class quick_partition: public partition
{
public:
	size_t operator()(int arr[], const size_t n, const comparator& comp) const override { return partition(arr, n, comp); }

	static size_t partition(int arr[], size_t n, const comparator& comp);
};
