#include <iostream>
#include <string>
#include "timer.hpp"
#include "assert.hpp"
#include "array_utils.hpp"
#include "bubble_sort.hpp"
#include "insertion_sort.hpp"
#include "selection_sort.hpp"
#include "maximum.hpp"
#include "quick_partition.hpp"
#include "quick_sort.hpp"
#include "merge_sort.hpp"
#include "shell_sort.hpp"
#include "dual_pivot_quick_sort.hpp"
#include "counting_sort.hpp"
#include "radix_sort.hpp"
#include "bucket_sort.hpp"
#include "comb_sort.hpp"
#include "simple_indexer.hpp"
#include "radix_indexer.hpp"
#include "comb_gapper.hpp"
#include "swapper.hpp"

using std::cout;
using std::endl;
using std::string;

int main(int argc, char** argv)
{
	const size_t n = 10000;
	int* arr = arr_random_natural(n);

	shell_sort sort;
	desc_comparator comp;
	sort(arr, n, comp);

	check_arr_sorted(arr, n, comp);

	return 0;
}
