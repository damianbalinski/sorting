#pragma once
#include "operation.hpp"
#include "multi_pivot_selector.hpp"

class multi_pivot_partition
{
public:
	multi_pivot_partition(const multi_pivot_selector* const selector): selector(selector) {}

	virtual size_t* operator()(int arr[], size_t n, size_t number_of_pivots, const operation& oper) const = 0;

protected:
	const multi_pivot_selector* const selector;
};
