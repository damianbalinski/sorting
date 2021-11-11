#pragma once
#include "operation.hpp"

class multi_pivot_selector
{
public:
	virtual const char* name() const = 0;

	virtual size_t* operator()(int arr[], size_t n, size_t number_of_pivots, const operation& oper) const = 0;
};
