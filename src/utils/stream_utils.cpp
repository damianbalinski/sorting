#include "stream_utils.hpp"
#include <fmt/format.h>

void save_row(std::ostream& ostream, const testing_row& row)
{
	const testing_results& r = row.results;
	const testing_invariants& i = row.invariants;
	const std::string s = fmt::format("{},{},{},{},{},{},{}\n",
		i.id_global, i.id, r.comparisons, r.swaps, r.assigns, i.n, i.sorting_name);
		
	ostream << s;
}
