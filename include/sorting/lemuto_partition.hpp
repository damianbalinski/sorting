#pragma once
#include "partition.hpp"
#include "pivot_selector.hpp"
#include "string_utils.hpp"

class lemuto_partition: public partition
{
public:
	const char* name() const override { return concat("", selector->name()); }

	lemuto_partition(const pivot_selector* const selector) : partition(selector) {}

	partition_result operator()(int arr[], const size_t n, const operation& oper) const override { return partitione(arr, n, oper); }

	partition_result partitione(int arr[], size_t n, const operation& oper) const;

private:
	static partition_result prepare_partition_result(int arr[], size_t n, size_t pivot);
};
