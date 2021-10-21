#pragma once
#include "testing_unit.hpp"

class testing_averager
{
public:
	testing_averager(const testing_unit& unit):
		sorting_name(unit.sorting_name), repeats(unit.repeats), n(unit.n),
		all_comparisons(0), all_swaps(0), all_assigns(0) {}

	void add(const testing_results& results);

private:
	const char* const sorting_name;
	const size_t repeats;
	const size_t n;

	size_t all_comparisons;
	size_t all_swaps;
	size_t all_assigns;
};