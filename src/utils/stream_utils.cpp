#include "stream_utils.hpp"
#include <fmt/format.h>
#include <fmt/ostream.h>
#include <scn/scn.h>

void save_results(std::ostream& output, const size_t n, const results& results)
{
	fmt::print(output, "{},{},{},{},{},{},{}\n",
		n, results.comparisons, results.swaps, results.assigns, results.time, results.cost, results.factor);
}
