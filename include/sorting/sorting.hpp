#pragma once
#include "comparator.hpp"

class sorting
{
public:
	virtual void operator()(int arr[], size_t n, comparator& comp) = 0;
};
