#pragma once
#include "sorting.hpp"

class counting_sort : public sorting
{
public:
	static int MAX;
	void operator()(int arr[], const size_t n, const comparator& comp) const override { sort(arr, n, MAX); }

private:
	static void sort(int arr[], size_t n, int max);
};
