#pragma once
#include "sorting.hpp"
#include "simple_indexer.hpp"

class counting_sort : public sorting
{
public:
	static const size_t MAX;
	
	void operator()(int arr[], const size_t n, const operation& oper) const override { sort(arr, n, oper, simple_indexer(MAX)); }
	
	static void sort(int arr[], size_t n, const operation& oper, const indexer& indexer);
};
