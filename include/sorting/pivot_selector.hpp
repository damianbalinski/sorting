#pragma once
#include "operation.hpp"

class pivot_selector
{
public:
	virtual const char* name() const = 0;

	virtual void operator()(int arr[], size_t n, size_t pos, const operation& oper) const = 0;

protected:
	static void swap_pivot_in_position(int arr[], const size_t pivot, const size_t pos, const operation& oper)
	{
		if (pivot != pos) oper.swap(&arr[pivot], &arr[pos]);
	}
};
