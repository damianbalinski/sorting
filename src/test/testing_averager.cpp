#include "testing_averager.hpp"
#include "numeric_utils.hpp"
#include "assert.hpp"

void testing_averager::add(const testing_results& results)
{
	check_num_greater_than(repeats, counter);
	comparisons = safe_add(comparisons, results.comparisons);
	swaps = safe_add(swaps, results.swaps);
	assigns = safe_add(assigns, results.assigns);
	counter++;
}

testing_results testing_averager::average_results() const
{
	check_num_equal(repeats, counter);
	return testing_results{ comparisons/repeats, swaps/repeats, assigns/repeats };
}
