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
	const int n = 10000;
	const desc_comparator comp;
	const selection_sort sort;
	int* arr = arr_random_natural(n);

	cout << arr_to_string_with_ids(arr, n) << endl;
	sort(arr, n, comp);
	cout << arr_to_string_with_ids(arr, n) << endl;
	check_arr_sorted(arr, n, comp);
	
	return 0;
}
