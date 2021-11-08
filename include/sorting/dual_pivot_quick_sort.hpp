#pragma once
#include "sorting.hpp"
#include "multi_pivot_partition.hpp"
class dual_pivot_quick_sort : public sorting
{
public:
	dual_pivot_quick_sort(const multi_pivot_partition* const partition): partition(partition) {}

	const char* name() const override { return "dual_pivot_quick_sort"; }

	void operator()(int arr[], const size_t n, const operation& oper) const override { sort(arr, n, oper); }

private:
	const multi_pivot_partition* const partition;

	void sort(int arr[], size_t n, const operation& oper) const;
};
