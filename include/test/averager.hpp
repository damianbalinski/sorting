#pragma once
#include "results.hpp"

class averager
{
public:
	averager(const size_t repeats) :
		repeats(repeats), counter(0), comparisons(0), swaps(0), assigns(0), time(0) {}

	void add(const results& results);

	results average_results() const;

private:
	const size_t repeats;
	size_t counter;
	size_t comparisons;
	size_t swaps;
	size_t assigns;
	size_t time;
};