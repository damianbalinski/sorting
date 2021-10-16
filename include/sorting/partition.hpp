#pragma once
#include "operation.hpp"

class partition
{
public:
	virtual size_t operator()(int arr[], size_t n, const operation& oper) const = 0;
};
