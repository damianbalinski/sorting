#pragma once
#include "indexer.hpp"

class bucket_indexer : public indexer
{
public:
	const size_t buckets;
	
	bucket_indexer(const size_t max, const size_t buckets) : indexer(max), buckets(buckets) {}

	size_t operator()(const int arr[], const size_t i) const override { return index(arr, i); }

private:
	size_t index(const int arr[], size_t i) const;
};
