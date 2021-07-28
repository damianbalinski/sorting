#include "maximum.hpp"
#include "assert.hpp"

int maximum(int* const arr, const size_t n, const comparator& comp)
{
	check_num_greater_than_zero(n);
	int max = arr[0];

	for (size_t i = 1; i < n; i++)
	{
		if (comp.gt(arr[i], max))
			max = arr[i];
	}
	return max;
}

size_t maximum_index(int* const arr, const size_t n, const comparator& comp)
{
	check_num_greater_than_zero(n);
	size_t max = 0;

	for (size_t i = 1; i < n; i++)
	{
		if (comp.gt(arr[i], arr[max]))
			max = i;
	}
	return max;
}
