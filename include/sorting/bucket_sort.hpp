#pragma once
#include "sorting.hpp"
#include "bucket_indexer.hpp"
#include "bubble_sort.hpp"

class bucket_sort : public sorting
{
public:
	static const size_t MAX;

	static const size_t BUCKETS;
	
	void operator()(int arr[], const size_t n, const comparator& comp) const override { sort(arr, n, bucket_indexer(MAX, BUCKETS), bubble_sort()); }

private:
	static void sort(int arr[], size_t n, const bucket_indexer& indexer, const sorting& sort);
};
