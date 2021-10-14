#pragma once
#include "multi_pivot_selector.hpp"

class simple_dual_pivot_selector : public multi_pivot_selector
{
public:
	size_t* operator()(int arr[], const size_t n, const size_t number_of_pivots, const comparator& comp) const override { return select(arr, n, comp); }

private:
	static size_t* select(int arr[], size_t n, const comparator& comp);
};
