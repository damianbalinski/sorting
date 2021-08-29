#pragma once
#include "sorting.hpp"
#include "gapper.hpp"
#include "comb_gapper.hpp"

class comb_sort : public sorting
{
public:
	void operator()(int arr[], const size_t n, const comparator& comp) const override { sort(arr, n, comp, comb_gapper()); }

private:
	static void sort(int arr[], size_t n, const comparator& comp, const gapper& gapper);
};
