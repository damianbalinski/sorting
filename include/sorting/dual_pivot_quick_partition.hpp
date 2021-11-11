#pragma once
#include "multi_pivot_partition.hpp"
#include "multi_pivot_selector.hpp"
#include "string_utils.hpp"

class dual_pivot_quick_partition: public multi_pivot_partition
{
public:
	const char* name() const override { return concat("", selector->name()); }

	dual_pivot_quick_partition(const multi_pivot_selector* const selector): multi_pivot_partition(selector) {}

	size_t* operator()(int arr[], size_t n, size_t number_of_pivots, const operation& oper) const override { return partitione(arr, n, oper); }

	size_t* partitione(int arr[], size_t n, const operation& oper) const;
};
