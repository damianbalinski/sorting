#include "counting_sort.hpp"
#include "array_utils.hpp"

size_t const counting_sort::MAX = 1024;

void counting_sort::sort(int arr[], const size_t n, const operation& oper, const indexer& indexer)
{
	int* res = new int[n];
	size_t* count = new size_t[indexer.max]();

	for (size_t i = 0; i < n; i++)
		count[indexer(arr,i)]++;

	for (size_t i = 1; i < indexer.max; i++)
		count[i] += count[i-1];

	for (size_t i = n; i > 0; i--)
	{
		const size_t j = i-1;
		res[count[indexer(arr,j)]-1] = oper.assign(arr[j]);
		count[indexer(arr,j)]--;
	}

	oper.arr_copy(arr, res, n);
	delete [] res;
	delete [] count;
}
