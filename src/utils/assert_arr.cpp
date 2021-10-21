#include "assert_arr.hpp"
#include "array_utils.hpp"
#include "colors.hpp"
#include <iostream>
#include <fmt/format.h>

inline void __pretty_arr_assertion(const int* const arr, const size_t n, const std::string& msg)
{
	std::cerr << "assertion failed" << std::endl;
	std::cerr << RED << arr_to_string_with_ids(arr, n) << msg << WHITE << std::endl;
	std::cerr << "program is aborted" << std::endl;
	abort();
}

void __check_arr_sorted(const int* const arr, const size_t n, const operation& oper)
{
	for (size_t i = 0; i < n - 1; i++)
	{
		if (oper.gt(arr[i], arr[i + 1]))
		{
			__pretty_arr_assertion(arr, n,
				fmt::format("Array is not sorted at positions {} and {} [{}, {}]", i, i + 1, arr[i], arr[i + 1])
			);
		}
	}
}

void __check_arr_partitioned(const int* const arr, const size_t n, const size_t pivot, const operation& oper)
{
	for (size_t i = 0; i < pivot; i++)
	{
		if (oper.gt(arr[i], arr[pivot]))
		{
			__pretty_arr_assertion(arr, n,
				fmt::format("Array is not partitioned at position {} [{}], pivot {} [{}]", i, arr[i], pivot, arr[pivot])
			);
		}
	}

	for (size_t i = pivot + 1; i < n; i++)
	{
		if (oper.lt(arr[i], arr[pivot]))
		{
			__pretty_arr_assertion(arr, n,
				fmt::format("Array is not partitioned at position {} [{}], pivot {} [{}]", i, arr[i], pivot, arr[pivot])
			);
		}
	}
}

void __check_arr_is_binary_max_heap(const int* const arr, const size_t n, const operation& oper)
{
	for (size_t i = 0; i < n; i++)
	{
		const size_t left = 2 * i + 1;
		if (left < n && oper.gt(arr[left], arr[i]))
		{
			__pretty_arr_assertion(arr, n,
				fmt::format("Array is not binary max heap at position {} [{}], left {} [{}]", i, arr[i], left, arr[left])
			);
		}

		const size_t right = 2 * i + 2;
		if (right < n && oper.gt(arr[right], arr[i]))
		{
			__pretty_arr_assertion(arr, n,
				fmt::format("Array is not binary max heap at position {} [{}], right {} [{}]", i, arr[i], right, arr[right])
			);
		}
	}
}

void __check_arr_equal(const int* const arr1, const int* const arr2, const size_t n, const operation& oper)
{
	for (size_t i = 0; i < n; i++)
	{
		if (oper.ne(arr1[i], arr2[i]))
		{
			__pretty_arr_assertion(arr1, n,
				fmt::format("Arrays are not equal at position {} [{} != {}]", i, arr1[i], arr2[i])
			);
		}
	}
}
