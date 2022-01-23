#include "assert_arr.hpp"
#include "array_utils.hpp"
#include "hoare_partition.hpp"
#include "lomuto_partition.hpp"
#include "operation.hpp"
#include "middle_pivot_selector.hpp"
#include "simple_pivot_selector.hpp"
#include "quick_sort.hpp"
#include "merge_sort.hpp"
#include "intro_sort.hpp"
#include "quick_merge_sort.hpp"
#include "dual_pivot_quick_sort.hpp"
#include "quick_merge_intro_sort.hpp"
#include "dual_pivot_quick_partition.hpp"
#include "simple_dual_pivot_selector.hpp"
#include "median_of_three_pivot_selector.hpp"
#include "pseudo_median_of_nine_pivot_selector.hpp"
#include "median_of_medians_of_five_pivot_selector.hpp"
#include "median_of_medians_of_three_pivot_selector.hpp"
#include "random_pivot_selector.hpp"
#include "median_of_three_choices_pivot_selector.hpp"
#include "median_of_five.hpp"
#include "random_generator.hpp"
#include "reversed_generator.hpp"
#include "almost_sorted_generator.hpp"
#include "hard_merge_generator.hpp"
#include "sorted_generator.hpp"
#include "debugger.hpp"

#include <iostream>
using namespace std;

int test()
{
	const operation oper{ asc_comparator{}, simple_swapper{}, simple_assigner{} };
	const sorted_generator generator{};
	const median_of_three_choices_pivot_selector selector{};
	const sorting *sort = new quick_merge_intro_sort{new lomuto_partition{new median_of_three_pivot_selector{}}};
	for (int i = 0; i < 1; i++)
	{
		const size_t n = 1000;
		int* arr = generator(n);
		(*sort)(arr, n, oper);
		check_arr_sorted(arr, n, oper);
		delete [] arr;
	}

	return 0;
}
