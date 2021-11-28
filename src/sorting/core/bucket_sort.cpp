#include "bucket_sort.hpp"
#include "array_utils.hpp"
#include <vector>

size_t const bucket_sort::MAX = 1024;

size_t const bucket_sort::BUCKETS = 10;

void bucket_sort::sort(int arr[], const size_t n, const operation& oper, const bucket_indexer& indexer, const sorting& sort)
{
	auto const buckets = new std::vector<int>[indexer.buckets];

	for (size_t i = 0; i < n; i++)
		buckets[indexer(arr, i)].push_back(arr[i]);

	for (size_t b = 0; b < indexer.buckets; b++)
		sort(buckets[b].data(), buckets[b].size(), oper);

	size_t k = 0;
	for (size_t b = 0; b < indexer.buckets; b++)
	{
		const size_t m = buckets[b].size();
		oper.arr_copy(arr + k, buckets[b].data(), m);
		k += m;
	}
	
	delete [] buckets;
}
