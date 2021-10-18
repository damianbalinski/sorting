#pragma once
#include "sorting.hpp"

class radix_sort : public sorting
{
public:
	const char* name() const override { return "radix_sort"; }

	void operator()(int arr[], const size_t n, const operation& oper) const override { sort(arr, n, oper); }

private:
	static void sort(int arr[], size_t n, const operation& oper);
};
