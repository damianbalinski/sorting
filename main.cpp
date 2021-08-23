﻿#include <iostream>
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

using std::cout;
using std::endl;
using std::string;

int main(int argc, char** argv)
{
	const int n = 10000;
	const desc_comparator comp;
	const dual_pivot_quick_sort sort;
	int* arr = arr_random_natural(n);
	//timer(
	//	[&]() { sort(arr, n, comp); }
	//);
	sort(arr, n, comp);
	check_arr_sorted(arr, n, comp);

	
	return 0;
}
