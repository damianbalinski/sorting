#include <iostream>
#include <map>

#include "bubble_sort.hpp"
#include "array_utils.hpp"
#include "assert.hpp"

using std::cout;
using std::endl;
using std::string;

int main(int argc, char** argv)
{
	int* arr = new int[]{20, 19, 18, 17};
	int n = 4;
	
	bubble_sort sort;
	asc_comparator asc;

	cout << arr_to_string(arr, n) << endl;
	sort(arr, 4, asc);
	cout << arr_to_string(arr, n) << endl;
	check_arr_sorted(arr, n, asc);
	
	return 0;
}
