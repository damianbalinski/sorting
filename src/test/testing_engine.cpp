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

void testing_engine::start() const
{
	size_t id_global = 0;
	for (const testing_unit& unit: testing_units)
	{
		PROGRESS_INIT(fmt::format("{:28}  {:6} ", unit.sorting_name, unit.n));
		for (size_t id = 0; id < unit.repeats; )
		{
			PROGRESS_STEP(id, unit.repeats);
			save_row(ostream, test(unit, id_global++, id++));
		}
		PROGRESS_END();
	}
}

testing_row testing_engine::test(const testing_unit& unit, const size_t id_global, const size_t id) const
{
	const testing_result result = test_sorting(unit.sorting, unit.n);
	return testing_row{
		id_global,
		id,
		unit.sorting_name,
		unit.n,
		result.comparisons,
		result.swaps,
		result.assigns
	};
}

testing_result testing_engine::test_sorting(const sorting& sort, const size_t n) const
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

	return testing_result{COMPARISONS, SWAPS, ASSIGNS};
}
