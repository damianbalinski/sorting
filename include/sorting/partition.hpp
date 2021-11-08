#pragma once
#include "operation.hpp"
#include "pivot_selector.hpp"

class partition
{
public:
	partition(const pivot_selector* const selector): selector(selector) {}

	virtual size_t operator()(int arr[], size_t n, const operation& oper) const = 0;

protected:
	const pivot_selector* const selector;
};
