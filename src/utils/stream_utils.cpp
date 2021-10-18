#include "stream_utils.hpp"
#include <fmt/format.h>

void save_row(std::ostream& ostream, const testing_row& r)
{
	const std::string s = fmt::format("{},{},{},{},{},{},{}\n",
		r.id_global, r.id, r.sorting_name, r.n, r.comparisons, r.swaps, r.assigns);
		
	ostream << s;
}