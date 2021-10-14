#pragma once
#include "pivot_selector.hpp"

class median_of_three_pivot_selector : public pivot_selector
{
public:
	size_t operator()(int arr[], const size_t n, const comparator& comp) const override { return select(arr, n, comp); }

private:
	static size_t select(int arr[], size_t n, const comparator& comp);
};
