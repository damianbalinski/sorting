#include "radix_sort.hpp"
#include "maximum.hpp"
#include "counting_sort.hpp"
#include "radix_indexer.hpp"

void radix_sort::sort(int arr[], const size_t n, const operation& oper)
{
	const int max = maximum(arr, n, oper);

	for (int exp = 1; max/exp > 0; exp *= 10)
		counting_sort::sort(arr, n, oper, radix_indexer(10, exp));
}
