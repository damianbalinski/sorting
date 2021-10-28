#pragma once
#include "range.hpp"

class testing_group
{
public:
	testing_group(const sorting& sorting, const size_t repeats, const range& range) :
		sorting(sorting), repeats(repeats), range(range) {}

	const sorting& sorting;
	const size_t repeats;
	const range& range;
};
