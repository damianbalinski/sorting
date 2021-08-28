#pragma once
#include "indexer.hpp"

class simple_indexer: public indexer
{
public:
	size_t operator()(const int arr[], const size_t i) const override { return index(arr, i); }

private:
	static size_t index(const int arr[], size_t i);
};