#include "assert.hpp"
#include "array_utils.hpp"
#include <iostream>
#include <string>
#include <fmt/format.h>

#define RED     "\033[31m"
#define WHITE   "\033[37m"

inline void __pretty_assertion(const std::string& msg)
{
	std::cerr << "assertion failed" << std::endl;
	std::cerr << RED << msg << WHITE << std::endl;
	std::cerr << "program is aborted" << std::endl;
	abort();
}

inline void __pretty_assertion_with_arr(const int* const arr, const size_t n, const std::string& msg)
{
	std::cerr << "assertion failed" << std::endl;
	std::cerr << RED << arr_to_string_with_ids(arr, n) << msg << WHITE << std::endl;
	std::cerr << "program is aborted" << std::endl;
	abort();
}

void __check_num_in_range(const int a, const int min, const int max)
{
	if (!(a >= min && a <= max))
		__pretty_assertion(fmt::format("Number {} is not in range ({}, {})", a, min, max));
}

void __check_num_in_range_right_open(const size_t a, const size_t min, const size_t max)
{
	if (!(a >= min && a < max))
		__pretty_assertion(fmt::format("Number {} is not in range ({}, {})", a, min, max));
}

void __check_num_greater_than_zero(const int n)
{
	if (!(n > 0))
		__pretty_assertion(fmt::format("Number {} is not greater than zero", n));
}

void __check_num_greater_than_other(const int a, const int b)
{
	if (!(a > b))
		__pretty_assertion(fmt::format("Number {} is not greater than {}", a, b));
}

void __check_arr_sorted(const int* const arr, const size_t n, const comparator& comp)
{
	for (size_t i = 0; i < n - 1; i++)
	{
		if (comp.gt(arr[i], arr[i + 1]))
		{
			__pretty_assertion_with_arr(arr, n,
				fmt::format("Array is not sorted at positions {} and {} [{}, {}]",i, i+1, arr[i], arr[i+1])
			);
		}
	}
}

void __check_arr_partitioned(const int* const arr, const size_t n, const size_t pivot, const comparator& comp)
{
	for (size_t i = 0; i < pivot; i++)
	{
		if (comp.gt(arr[i], arr[pivot]))
		{
			__pretty_assertion_with_arr(arr, n,
				fmt::format("Array is not partitioned at position {} [{}], pivot {} [{}]", i, arr[i], pivot, arr[pivot])
			);
		}
	}

	for (size_t i = pivot+1; i < n; i++)
	{
		if (comp.lt(arr[i], arr[pivot]))
		{
			__pretty_assertion_with_arr(arr, n,
				fmt::format("Array is not partitioned at position {} [{}], pivot {} [{}]", i, arr[i], pivot, arr[pivot])
			);
		}
	}
}

void __check_arr_equal(const int* const arr1, const int* const arr2, const size_t n, const comparator& comp)
{
	for (size_t i = 0; i < n; i++)
	{
		if (comp.ne(arr1[i], arr2[i]))
		{
			__pretty_assertion_with_arr(arr1, n,
				fmt::format("Arrays are not equal at position {} [{} != {}]", i, arr1[i], arr2[i])
			);
		}
	}
}
