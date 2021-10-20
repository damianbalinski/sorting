#include "testing_engine.hpp"
#include "operation.hpp"
#include "progress.hpp"
#include "array_utils.hpp"
#include "stream_utils.hpp"
#include "assert.hpp"
#include <fmt/format.h>

void testing_engine::add(const sorting& sorting, const size_t repeats, const size_t n)
{
	testing_units.emplace_back(testing_unit(sorting, repeats, n));
}

void testing_engine::add(const sorting& sorting, const size_t repeats, const range& range)
{
	for(size_t n = range.begin; n <= range.end; n += range.step)
		testing_units.emplace_back(testing_unit(sorting, repeats, n));
}

void testing_engine::testing(std::ostream& ostream) const
{
	size_t id_global = 0;
	for (const testing_unit& unit: testing_units)
	{
		PROGRESS_INIT(fmt::format("{:28}  {:6} ", unit.sorting_name, unit.n));
		for (size_t id = 0; id < unit.repeats; )
		{
			PROGRESS_STEP(id, unit.repeats);
			const testing_invariants invariants{ id_global++, id++, unit.n, unit.sorting_name };
			const testing_results results = test(unit.sorting, unit.n);
			save_row(ostream, testing_row{ invariants, results });
		}
		PROGRESS_END();
	}
}

void testing_engine::statistics(std::istream& istream) const
{
	size_t id_global = 0;
	for (const testing_unit& unit : testing_units)
	{
		PROGRESS_INIT(fmt::format("{:28}  {:6} ", unit.sorting_name, unit.n));
		for (size_t id = 0; id < unit.repeats; )
		{
			PROGRESS_STEP(id, unit.repeats);
			const testing_invariants invariants{ id_global++, id++, unit.n, unit.sorting_name };
			const testing_row row = read_row(istream, invariants);
		}
		PROGRESS_END();
	}
}

testing_results testing_engine::test(const sorting& sort, const size_t n) const
{
	int* arr = arr_random_natural(n);

	size_t COMPARISONS = 0;
	size_t SWAPS = 0;
	size_t ASSIGNS = 0;

	operation oper(
		counting_asc_comparator{ &COMPARISONS },
		counting_swapper{ &SWAPS },
		counting_assigner{ &ASSIGNS }
	);

	sort(arr, n, oper);
	check_arr_sorted(arr, n, oper);

	delete [] arr;

	return testing_results{ COMPARISONS, SWAPS, ASSIGNS };
}