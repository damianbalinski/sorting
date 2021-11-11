#pragma once
#include "multi_pivot_selector.hpp"

class simple_dual_pivot_selector : public multi_pivot_selector
{
public:
	const char* name() const override { return ""; }

	size_t* operator()(int arr[], const size_t n, const size_t number_of_pivots, const operation& oper) const override { return select(arr, n, oper); }

private:
	static size_t* select(int arr[], size_t n, const operation& oper);
};
