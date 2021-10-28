#pragma once
#include "testing_results.hpp"

class testing_averager
{
public:
	testing_averager(const size_t repeats):
		repeats(repeats), counter(0), comparisons(0), swaps(0), assigns(0), time(0) {}

	void add(const testing_results& results);

	testing_results average_results() const;

private:
	const size_t repeats;
	size_t counter;

	size_t comparisons;
	size_t swaps;
	size_t assigns;
	size_t time;
};
