#include "stream_utils.hpp"
#include "assert.hpp"
#include <fmt/format.h>
#include <fmt/ostream.h>
#include <fstream>
#include <scn/scn.h>

void save_row(std::ostream& ostream, const testing_row& row)
{
	const testing_results& r = row.results;
	const testing_invariants& i = row.invariants;
	fmt::print(ostream, "{},{},{},{},{},{},{}\n",
		i.id_global, i.id, r.comparisons, r.swaps, r.assigns, i.n, i.sorting_name);
}

testing_row read_row(std::istream& istream, const testing_invariants& invariants)
{
	size_t comparisons, swaps, assigns;
	size_t id_global, id, n;
	std::string sorting_name;

	std::string s;
	istream >> s;

	scn::scan(s, "{},{},{},{},{},{},{}",
		id_global, id, comparisons, swaps, assigns, n, sorting_name);

	check_num_equal(id_global, invariants.id_global);
	check_num_equal(id, invariants.id);
	check_num_equal(n, invariants.n);

	const testing_results results{ comparisons, swaps, assigns };
	return testing_row{ invariants, results };
}
