#include "bucket_indexer.hpp"
#include "assert.hpp"

size_t bucket_indexer::index(const int arr[], const size_t i) const
{
	const size_t id = arr[i];
	check_num_in_range_right_open(id, 0, max);

	return arr[i] * buckets / max;
}
