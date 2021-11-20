#pragma once

class results
{
public:

	results(const size_t comparisons, const size_t swaps, const size_t assigns, const size_t time, const double factor) :
		comparisons(comparisons), swaps(swaps), assigns(assigns), time(time), all(factor*comparisons + 3*swaps + assigns), factor(factor) {}

	const size_t comparisons;
	const size_t swaps;
	const size_t assigns;
	const size_t time;
	const size_t all;
	const double factor;
};
