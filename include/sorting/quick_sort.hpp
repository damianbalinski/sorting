#pragma once
#include "sorting.hpp"

class quick_sort : public sorting
{
public:
	const char* name() const override { return "quick_sort"; }

	void operator()(int arr[], const size_t n, const operation& oper) const override { sort(arr, n, oper); }

private:
	static void sort(int arr[], size_t n, const operation& oper);
};
