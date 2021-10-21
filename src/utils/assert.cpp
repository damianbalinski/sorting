#include "assert.hpp"
#include "colors.hpp"
#include <iostream>
#include <string>
#include <fmt/format.h>

inline void __pretty_assertion(const std::string& msg)
{
	std::cerr << "assertion failed" << std::endl;
	std::cerr << RED << msg << WHITE << std::endl;
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

void __check_num_greater_than(const int a, const int b)
{
	if (!(a > b))
		__pretty_assertion(fmt::format("Number {} is not greater than {}", a, b));
}

void __check_num_greater_than_or_equal_to(size_t a, size_t b)
{
	if (!(a >= b))
		__pretty_assertion(fmt::format("Number {} is not greater than or equal to {}", a, b));
}

void __check_num_equal(const size_t a, const size_t b)
{
	if (!(a == b))
		__pretty_assertion(fmt::format("Number {} is not equal to {}", a, b));
}

void __check_num_add_overflow(const size_t a, const size_t b)
{
	if (!(a+b >= a))
		__pretty_assertion(fmt::format("Adding {} into {} causes overflow", b, a));
}
