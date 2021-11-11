#pragma once
#include "multi_pivot_partition_result.hpp"
#include "multi_pivot_partition.hpp"
#include "multi_pivot_selector.hpp"
#include "string_utils.hpp"

class dual_pivot_quick_partition: public multi_pivot_partition
{
public:
	const char* name() const override { return concat("", selector->name()); }

	dual_pivot_quick_partition(const multi_pivot_selector* const selector): multi_pivot_partition(selector) {}

	multi_pivot_partition_result operator()(int arr[], size_t n, size_t number_of_pivots, const operation& oper) const override { return partitione(arr, n, oper); }

	multi_pivot_partition_result partitione(int arr[], size_t n, const operation& oper) const;

private:
	static multi_pivot_partition_result prepare_partition_result(int arr[], size_t n, size_t pivot1, size_t pivot2);
};
