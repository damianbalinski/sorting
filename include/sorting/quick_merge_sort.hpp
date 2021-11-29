#pragma once
#include "sorting.hpp"
#include "partition.hpp"
#include "string_utils.hpp"

class quick_merge_sort : public sorting
{
public:
	quick_merge_sort(const partition* const partition) : partition(partition) {}

	const char* name() const override { return concat("quick_merge_sort", partition->name()); }

	void operator()(int arr[], const size_t n, const operation& oper) const override { sort(arr, n, oper); }

private:
	const partition* const partition;

	void sort(int arr[], size_t n, const operation& oper) const;
};
