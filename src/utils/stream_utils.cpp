#include "stream_utils.hpp"
#include "assert.hpp"
#include <fmt/format.h>
#include <fmt/ostream.h>
#include <fstream>
#include <scn/scn.h>

void save_row(std::ostream& ostream, const testing_invariants& invariants,
const testing_results& results, const testing_identifier& identifier)
{
	fmt::print(ostream, "{},{},{},{},{},{},{},{},{}\n",
		identifier.id_global, identifier.id,
		results.comparisons, results.swaps, results.assigns, results.time, results.all,
		invariants.n, invariants.sorting_name);
}

void save_results(std::ostream& ostream, const testing_invariants& invariants,
const testing_results& results)
{
	fmt::print(ostream, "{},{},{},{},{},{},{}\n",
		invariants.sorting_name, invariants.n,
		results.comparisons, results.swaps, results.assigns, results.time, results.all);
}

testing_results read_results(std::istream& istream, const testing_identifier& identifier)
{
	size_t comparisons, swaps, assigns, time;
	size_t id_global, id;

	std::string s;
	istream >> s;

	scn::scan(s, "{},{},{},{},{},{},{},{},{}",
		id_global, id, comparisons, swaps, assigns, time);

	check_num_equal(id_global, identifier.id_global);
	check_num_equal(id, identifier.id);

	return testing_results{ comparisons, swaps, assigns, time };
}
