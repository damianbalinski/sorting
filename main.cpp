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

using std::cout;
using std::endl;
using std::string;

int main(int argc, char** argv)
{
	const int n = 100000;
	int* arr = arr_random_in_range(n, counting_sort::MAX);
	counting_sort sort;
	asc_comparator comp;

	sort(arr, n, comp);
	check_arr_sorted(arr, n, comp);
	
	return 0;
}
