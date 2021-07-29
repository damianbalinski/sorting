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

inline void __pretty_assertion_with_arr(int* const arr, const size_t n, const std::string& msg)
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

void __check_arr_sorted(int* const arr, const size_t n, const comparator& comp)
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

void __check_arr_partitioned(int* const arr, const size_t n, const size_t pivot, const comparator& comp)
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