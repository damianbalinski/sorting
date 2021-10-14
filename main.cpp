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
#include "simple_indexer.hpp"
#include "radix_indexer.hpp"
#include "comb_gapper.hpp"
#include "swapper.hpp"
#include "binary_max_heap.hpp"
#include "heap_sort.hpp"
#include "numeric_utils.hpp"
#include <algorithm>

using std::cout;
using std::endl;
using std::string;

int main(int argc, char** argv)
{
	const size_t n = 100;
	int* arr = arr_random_natural(n);
	asc_comparator comp;
	dual_pivot_quick_sort sort;

	sort(arr, n, comp);
	check_arr_sorted(arr, n, comp);

	cout << arr_to_string_with_ids(arr, n);
	
	return 0;
}
