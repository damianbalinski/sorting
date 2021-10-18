#pragma once

class testing_result
{
public:

	testing_result(const size_t comparisons, const size_t swaps, const size_t assigns):
		comparisons(comparisons), swaps(swaps), assigns(assigns) {}

	const size_t comparisons;
	const size_t swaps;
	const size_t assigns;
};
