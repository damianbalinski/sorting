#pragma once
#include "sorting.hpp"
#include "partition.hpp"

class quick_sort : public sorting
{
public:
	quick_sort(const partition* const partition): partition(partition) {}

	const char* name() const override { return "quick_sort"; }

	void operator()(int arr[], const size_t n, const operation& oper) const override { sort(arr, n, oper); }

private:
	const partition* const partition;

	void sort(int arr[], size_t n, const operation& oper) const;
};
