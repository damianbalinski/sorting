#pragma once
#include "comparator.hpp"

class multi_pivot_partition
{
public:
	virtual const size_t* operator()(int arr[], size_t n, size_t number_of_pivots, const comparator& comp) const = 0;
};
