#pragma once
#include "sorting.hpp"

class bubble_sort: public sorting
{
public:
	void operator()(int arr[], size_t n, comparator& comp) override { sort(arr, n, comp); }

private:
	static void sort(int arr[], size_t n, comparator& comp);
};
