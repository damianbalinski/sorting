#include "testing_averager.hpp"
#include "assert.hpp"

void testing_averager::add(const testing_results& results)
{
	check_addition_overflow(all_comparisons, results.comparisons);
	check_addition_overflow(all_swaps, results.swaps);
	check_addition_overflow(all_assigns, results.assigns);

	all_comparisons += results.comparisons;
	all_swaps += results.swaps;
	all_assigns += results.assigns;
}
