#pragma once
#include "sorting.hpp"
#include "half_gapper.hpp"

class shell_sort : public sorting
{
public:
	void operator()(int arr[], const size_t n, const comparator& comp) const override { sort(arr, n, comp, half_gapper()); }

private:
	static void sort(int arr[], size_t n, const comparator& comp, const gapper& gapper);
};
