#include "median_of_five.hpp"
#include "assert.hpp"
#include "insertion_sort.hpp"

size_t median_of_five_index(int arr[], size_t n, const operation& oper)
{
	check_num_greater_than_or_equal_to(5, n);
	insertion_sort::sort(arr, n, oper);
	return n/2;
}
