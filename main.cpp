#include <iostream>
#include <string>
#include "array_utils.hpp"
#include "bubble_sort.hpp"
#include "insertion_sort.hpp"
#include "selection_sort.hpp"
#include "assert.hpp"

using std::cout;
using std::endl;
using std::string;

int main(int argc, char** argv)
{
	const int n = 100;
	const desc_comparator comp;
	const selection_sort sort;
	int* arr = arr_random_natural(n);

	check_arr_sorted(arr, n, comp);
	
	return 0;
}
