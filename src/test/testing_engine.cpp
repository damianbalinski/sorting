#include "testing_engine.hpp"
#include "testing_averager.hpp"
#include "testing_identifier.hpp"
#include "operation.hpp"
#include "progress.hpp"
#include "array_utils.hpp"
#include "stream_utils.hpp"
#include "assert_arr.hpp"

void testing_engine::add(const sorting& sorting, const size_t repeats, const size_t n)
{
	testing_units.emplace_back(testing_unit{sorting, repeats, n});
}

void testing_engine::add(const sorting& sorting, const size_t repeats, const range& range)
{
	for (size_t n = range.begin; n <= range.end; n += range.step)
		add(sorting, repeats, n);
}

void testing_engine::testing(std::ostream& output) const
{
	PROGRESS_TITLE("TESTING");
	size_t id_global = 0;
	for (const testing_unit& unit: testing_units)
	{
		const testing_invariants& invariants = unit.invariants;

		PROGRESS_INIT(invariants.sorting_name, invariants.n);
		for (size_t id = 0; id < unit.repeats; )
		{
			PROGRESS_STEP(id, unit.repeats);
			const testing_results results = test(unit.sorting, invariants.n);
			save_row(output, invariants, results, testing_identifier{ id_global++, id++ });
		}
		PROGRESS_END();
	}
}

void testing_engine::statistics(std::istream& input, std::ostream& output) const
{
	PROGRESS_TITLE("STATISTICS");
	size_t id_global = 0;
	for (const testing_unit& unit : testing_units)
	{
		const testing_invariants& invariants = unit.invariants;
		testing_averager averager{ unit.repeats };

		PROGRESS_INIT(invariants.sorting_name, invariants.n);
		for (size_t id = 0; id < unit.repeats; )
		{
			PROGRESS_STEP(id, unit.repeats);
			const testing_results results = read_results(input, testing_identifier{ id_global++, id++ });
			averager.add(results);
		}
		PROGRESS_END();

		const testing_results results = averager.average_results();
		save_results(output, invariants, results);
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