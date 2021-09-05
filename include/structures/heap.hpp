#pragma once
#include "comparator.hpp"

class heap
{
public:
	virtual void operator()(int arr[], size_t n, const comparator& comp) const = 0;

	virtual void heapify(int arr[], size_t n, size_t i, const comparator& comp) const = 0;
};
