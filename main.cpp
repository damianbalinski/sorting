#include <iostream>
#include <string>
#include "array_utils.hpp"
#include "bubble_sort.hpp"
#include "assert.hpp"

using std::cout;
using std::endl;
using std::string;

int main(int argc, char** argv)
{
	const int n = 10000;
	const asc_comparator comp;
	const bubble_sort bubble_sort;
	int* arr = arr_random_natural(n);

	bubble_sort(arr, n, comp);
	check_arr_sorted(arr, n, comp);
	cout << arr_to_string(arr, n, '\n') << endl;
	
	return 0;
}
