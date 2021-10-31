#pragma once

class results
{
public:

	results(const size_t comparisons, const size_t swaps, const size_t assigns, const size_t time) :
		comparisons(comparisons), swaps(swaps), assigns(assigns), time(time), all(comparisons + 3 * swaps + assigns) {}

	const size_t comparisons;
	const size_t swaps;
	const size_t assigns;
	const size_t time;
	const size_t all;
};
