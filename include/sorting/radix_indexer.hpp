#pragma once
#include "indexer.hpp"

class radix_indexer : public indexer
{
public:
	radix_indexer(const size_t max, const size_t exp) : indexer(max), exp(exp) {}
	
	size_t operator()(const int arr[], const size_t i) const override { return index(arr, i); }

private:
	const size_t exp;
	
	size_t index(const int arr[], size_t i) const;
};
