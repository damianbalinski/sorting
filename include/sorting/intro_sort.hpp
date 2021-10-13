#pragma once
#include "sorting.hpp"
#include "numeric_utils.hpp"

class intro_sort : public sorting
{
public:
	void operator()(int arr[], const size_t n, const comparator& comp) const override { sort(arr, n, calculate_max_depth(n), comp); }

private:

	const static int MAX_DEPTH = 16;
	
	static void sort(int arr[], size_t n, size_t depth, const comparator& comp);

	static size_t calculate_max_depth(const size_t n) { return log2(n) * 2; }
};
