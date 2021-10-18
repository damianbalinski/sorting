#pragma once
#include "sorting.hpp"

class testing_unit
{
public:
	testing_unit(const sorting& sorting, const size_t repeats, const size_t n):
		sorting_name(sorting.name()), sorting(sorting), repeats(repeats), n(n) {}

	const char* sorting_name;
	const sorting& sorting;
	const size_t repeats;
	const size_t n;
};
