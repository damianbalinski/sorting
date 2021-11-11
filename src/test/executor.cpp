#include "executor.hpp"
#include "timer.hpp"
#include "assert_arr.hpp"

results executor::test(const generator* generator, const sorting* sorting, const size_t n) const
{
	int* arr = (*generator)(n);

	size_t COMPARISONS = 0;
	size_t SWAPS = 0;
	size_t ASSIGNS = 0;
	size_t TIME = 0;

	operation oper(
		counting_asc_comparator{ &COMPARISONS },
		counting_swapper{ &SWAPS },
		counting_assigner{ &ASSIGNS }
	);

	TIME = timer{
		[&]() { (*sorting)(arr, n, oper); }
	}.run();

	check_arr_sorted(arr, n, oper);

	delete[] arr;

	return results{ COMPARISONS, SWAPS, ASSIGNS, TIME };
}
