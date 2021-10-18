#pragma once
#include "sorting.hpp"
#include "numeric_utils.hpp"

class intro_sort : public sorting
{
public:
	const char* name() const override { return "intro_sort"; }

	void operator()(int arr[], const size_t n, const operation& oper) const override { sort(arr, n, calculate_max_depth(n), oper); }

private:

	const static int MAX_DEPTH = 16;
	
	static void sort(int arr[], size_t n, size_t depth, const operation& oper);

	static size_t calculate_max_depth(const size_t n) { return log2(n) * 2; }
};
