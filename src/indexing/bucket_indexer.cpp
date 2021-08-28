#include "bucket_indexer.hpp"

size_t bucket_indexer::index(const int arr[], const size_t i) const
{
	return arr[i] * buckets / max;
}
