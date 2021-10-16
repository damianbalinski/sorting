#pragma once
#include "partition.hpp"
#include "pivot_selector.hpp"

class quick_partition: public partition
{
public:
	size_t operator()(int arr[], const size_t n, const operation& oper) const override { return partition(arr, n, oper, DEFAULT_PIVOT_SELECTOR); }

	static size_t partition(int arr[], size_t n, const operation& oper, const pivot_selector& pivot_selector);

private:
	const static pivot_selector& DEFAULT_PIVOT_SELECTOR;
};
