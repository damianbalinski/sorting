#pragma once
#include "operation.hpp"
#include "multi_pivot_selector.hpp"
#include "multi_pivot_partition_result.hpp"

class multi_pivot_partition
{
public:
	virtual const char* name() const = 0;

	multi_pivot_partition(const multi_pivot_selector* const selector): selector(selector) {}

	virtual multi_pivot_partition_result operator()(int arr[], size_t n, size_t number_of_pivots, const operation& oper) const = 0;

protected:
	const multi_pivot_selector* const selector;
};
