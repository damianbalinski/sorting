#pragma once
#include "assert.hpp"

inline size_t log2(const size_t n)
{
	check_num_greater_than_zero(n);
	return log2(n*1.0);
}

inline size_t max(const size_t a, const size_t b)
{
	return (a>b) ? a : b;
}

inline size_t safe_mean_of_two(const size_t a, const size_t b)
{
	check_num_greater_than_or_equal_to(b, a);
	return a + (b - a) / 2;
}

inline size_t safe_add(const size_t a, const size_t b)
{
	check_num_add_overflow(a, b);
	return a + b;
}
