#pragma once
#include "sorting.hpp"
#include "numeric_utils.hpp"
#include "partition.hpp"

class intro_sort : public sorting
{
public:
	intro_sort(const partition* const partition) : partition(partition) {}

	const char* name() const override { return "intro_sort"; }

	void operator()(int arr[], const size_t n, const operation& oper) const override { sort(arr, n, calculate_max_depth(n), oper); }

private:

	const static int MAX_DEPTH = 16;

	const partition* const partition;
	
	void sort(int arr[], size_t n, size_t depth, const operation& oper) const;

	static size_t calculate_max_depth(const size_t n) { return log2(n) * 2; }
};
