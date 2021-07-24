#pragma once
#include <cassert>
#include "comparator.hpp"

inline void check_num_in_range(const int a, const int min, const int max)
{
	assert((a >= min && a <= max) && "Number is not in given range");
}

inline void check_arr_sorted(int* const arr, const size_t n, const comparator& comp)
{
	for (size_t i = 0; i < n-1; i++)
	{
		assert((comp.le(arr[i], arr[i + 1])) && "Array is not sorted");
	}
}

inline void check_greater_than_zero(const size_t n)
{
	assert((n > 0) && "Number is not greater than 0");
}

inline void check_greater_than_other(const size_t a, const size_t b)
{
	assert((a > b) && "Argument is not greater that the other");
}