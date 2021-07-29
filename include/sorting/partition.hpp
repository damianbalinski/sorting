#pragma once
#include "comparator.hpp"

class partition
{
public:
	virtual size_t operator()(int arr[], size_t n, const comparator& comp) const = 0;
};