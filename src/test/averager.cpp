#include "averager.hpp"
#include "assert.hpp"
#include "numeric_utils.hpp"

void averager::add(const results& results)
{
	check_num_greater_than(repeats, counter);
	comparisons = safe_add(comparisons, results.comparisons);
	swaps = safe_add(swaps, results.swaps);
	assigns = safe_add(assigns, results.assigns);
	time = safe_add(time, results.time);
	counter++;
}

results averager::average_results() const
{
	check_num_equal(repeats, counter);
	return results{ comparisons/repeats, swaps/repeats, assigns/repeats, time/repeats, factor };
}
