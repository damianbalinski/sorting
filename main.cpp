#include <iostream>
#include <string>
#include "array_utils.hpp"
#include "bubble_sort.hpp"
#include "insertion_sort.hpp"
#include "selection_sort.hpp"
#include "assert.hpp"
#include "maximum.hpp"
#include "quick_partition.hpp"

using std::cout;
using std::endl;
using std::string;

int main(int argc, char** argv)
{
	const int n = 10000;
	const asc_comparator comp;
	const bubble_sort sort;
	const quick_partition partition;
	int* arr = arr_random_natural(n);

	int pivot = partition(arr, n, comp);
	check_arr_partitioned(arr, n, pivot, comp);

	cout << pivot << endl;
	
	return 0;
}
