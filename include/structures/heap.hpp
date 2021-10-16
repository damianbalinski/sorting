#pragma once
#include "operation.hpp"

class heap
{
public:
	virtual void operator()(int arr[], size_t n, const operation& oper) const = 0;

	virtual void heapify(int arr[], size_t n, size_t i, const operation& oper) const = 0;
};
