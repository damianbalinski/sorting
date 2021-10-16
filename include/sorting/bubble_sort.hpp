#pragma once
#include "sorting.hpp"
#include "swapper.hpp"

class bubble_sort: public sorting
{
public:
	void operator()(int arr[], const size_t n, const operation& oper) const override { sort(arr, n, oper, swapper()); }

	static void sort(int arr[], size_t n, const operation& oper, const swapper& swapper);
};
