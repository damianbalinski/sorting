#pragma once
#include "sorting.hpp"
#include "bucket_indexer.hpp"
#include "bubble_sort.hpp"

class bucket_sort : public sorting
{
public:
	static const size_t MAX;

	static const size_t BUCKETS;

	const char* name() const override { return "bucket_sort"; }
	
	void operator()(int arr[], const size_t n, const operation& oper) const override { sort(arr, n, oper, bucket_indexer(MAX, BUCKETS), bubble_sort()); }

private:
	static void sort(int arr[], size_t n, const operation& oper, const bucket_indexer& indexer, const sorting& sort);
};
