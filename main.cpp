#include <iostream>
#include <string>
#include "array_utils.hpp"
#include "bubble_sort.hpp"
#include "insertion_sort.hpp"
#include "selection_sort.hpp"
#include "assert.hpp"
#include "maximum.hpp"

using std::cout;
using std::endl;
using std::string;

int main(int argc, char** argv)
{
	const int n = 5;
	const asc_comparator comp;
	int arr[] = {-10, -30, 100, -10, -3};

	int max = maximum_index(arr, n, comp);

	cout << max << endl;
	return 0;
}
