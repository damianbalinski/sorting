#pragma once
#include "sorting.hpp"

class bubble_sort: public sorting
{
public:
	void operator()(int arr[], const size_t n, const operation& oper) const override { sort(arr, n, oper); }

	static void sort(int arr[], size_t n, const operation& oper);
};
