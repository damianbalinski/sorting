#include "assert.hpp"
#include "array_utils.hpp"
#include <iostream>
#include <string>
#include <fmt/format.h>

#define RED     "\033[31m"
#define WHITE   "\033[37m"

inline void __pretty_assert(const bool condition, const std::string& msg)
{
	if (!condition)
	{
		std::cerr << "assertion failed" << std::endl;
		std::cerr << RED << msg << WHITE << std::endl;
		std::cerr << "program is aborted" << std::endl;
		abort();
	}
}

void __check_num_in_range(const int a, const int min, const int max)
{
	__pretty_assert((a >= min && a <= max),
		fmt::format("Number {} is not in range ({}, {})", a, min, max));
}

void __check_num_greater_than_zero(const int n)
{
	__pretty_assert((n > 0),
		fmt::format("Number {} is not greater than zero", n));
}

void __check_num_greater_than_other(const int a, const int b)
{
	__pretty_assert((a > b),
		fmt::format("Number {} is not greater than {}", a, b));
}

void __check_arr_sorted(int* const arr, const size_t n, const comparator& comp)
{
	for (size_t i = 0; i < n - 1; i++)
	{
		if (comp.le(arr[i], arr[i + 1]))
		{
			std::cerr << "assertion failed" << std::endl;
			std::cerr << RED << arr_to_string_with_ids(arr, n) << std::endl;
			std::cerr << fmt::format("Array is not sorted at positions {} and {} [{}, {}]", 
				i, i+1, arr[i], arr[i+1]) << WHITE << std::endl;
			std::cerr << "program is aborted" << std::endl;
			abort();
		}
	}
}