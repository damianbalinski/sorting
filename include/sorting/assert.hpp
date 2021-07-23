#pragma once
#include <cassert>
#include <string>
#include "comparator.hpp"

inline void check_num_in_range(int a, int min, int max, std::string msg)
{
	assert((a >= min && a <= max) && "Number is not in given range");
}

inline void check_arr_sorted(int arr[], int n, comparator& comp)
{
	for (size_t i = 0; i < n - 1; i++)
	{
		assert((comp.le(arr[i], arr[i + 1])) && "Array is not sorted");
	}
}
