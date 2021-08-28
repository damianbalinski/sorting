#include "radix_indexer.hpp"

size_t radix_indexer::index(const int arr[], const size_t i) const
{
	return (arr[i]/exp) % 10;
}
