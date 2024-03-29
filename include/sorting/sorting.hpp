#pragma once
#include "operation.hpp"

class sorting
{
public:
	virtual const char* name() const = 0;

	virtual void operator()(int arr[], size_t n, const operation& oper) const = 0;
};
