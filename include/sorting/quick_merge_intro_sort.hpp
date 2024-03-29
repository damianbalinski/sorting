#pragma once
#include "sorting.hpp"
#include "partition.hpp"
#include "string_utils.hpp"

class quick_merge_intro_sort : public sorting
{
public:
	quick_merge_intro_sort(const partition* const partition) : partition(partition) {}

	const char* name() const override { return concat("quick_merge_intro_sort", partition->name()); }

	void operator()(int arr[], const size_t n, const operation& oper) const override { sort(arr, n, calculate_max_depth(n), oper); }

private:
	const static int MAX_LENGTH = 19;

	const partition* const partition;

	void sort(int arr[], size_t n, size_t depth, const operation& oper) const;

	static size_t calculate_max_depth(const size_t n) { return safe_2log2(n); }
};
