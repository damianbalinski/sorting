#pragma once

class testing_results
{
public:

	testing_results(const size_t comparisons, const size_t swaps, const size_t assigns):
		comparisons(comparisons), swaps(swaps), assigns(assigns) {}

	const size_t comparisons;
	const size_t swaps;
	const size_t assigns;
};
