#include <iostream>
#include <string>
#include "timer.hpp"
#include "assert.hpp"
#include "array_utils.hpp"
#include "bubble_sort.hpp"
#include "insertion_sort.hpp"
#include "selection_sort.hpp"
#include "maximum.hpp"
#include "median_of_three.hpp"
#include "quick_partition.hpp"
#include "quick_sort.hpp"
#include "merge_sort.hpp"
#include "shell_sort.hpp"
#include "dual_pivot_quick_sort.hpp"
#include "counting_sort.hpp"
#include "radix_sort.hpp"
#include "bucket_sort.hpp"
#include "comb_sort.hpp"
#include "intro_sort.hpp"
#include "quick_merge_sort.hpp"
#include "simple_indexer.hpp"
#include "radix_indexer.hpp"
#include "comb_gapper.hpp"
#include "swapper.hpp"
#include "binary_max_heap.hpp"
#include "heap_sort.hpp"
#include "numeric_utils.hpp"
#include "debugger.hpp"
#include "colors.hpp"
#include "operation.hpp"
#include "swapper.hpp"
#include "assigner.hpp"

using std::cout;
using std::endl;
using std::string;

int main(int argc, char** argv)
{
	size_t COMPARISONS = 0;
	size_t SWAPS = 0;
	size_t ASSIGNS = 0;

	const size_t n = 10000;
	//int* arr = arr_random_natural(n);
	int* arr = arr_random_in_range(n, 1000);

	operation oper(
		counting_asc_comparator{&COMPARISONS},
		counting_swapper{&SWAPS},
		counting_assigner(&ASSIGNS)
	);
	
	insertion_sort sort;
	sort(arr, n, oper);
	check_arr_sorted(arr, n, oper);

	cout << "comparisons: " << COMPARISONS << endl;
	cout << "swaps      : " << SWAPS << endl;
	cout << "assigns    : " << ASSIGNS << endl;

	return 0;
}
