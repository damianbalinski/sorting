#include "median_of_medians_of_five_pivot_selector.hpp"
#include "median_of_five.hpp"
#include "numeric_utils.hpp"
#include "maximum.hpp"
#include "median_of_three.hpp"

size_t median_of_medians_of_five_pivot_selector::select(int arr[], const size_t n, const operation& oper)
{
	const size_t pivot = select_recursively(arr, n, oper);

	if (pivot != n - 1)
		oper.swap(&arr[pivot], &arr[n - 1]);
	return n - 1;
}

size_t median_of_medians_of_five_pivot_selector::select_recursively(int arr[], const size_t n, const operation& oper)
{
	if (n == 1) return 0;
	if (n == 2) return maximum_index(arr, 2, oper);
	if (n == 3) return median_of_three_index(arr, 0, n/2, n-1, oper);
	if (n <= 5) return median_of_five_index(arr, n, oper);

	const size_t max = (n+4)/5;
	for (size_t i = 0, j = 0; i < max; i++, j+=5)
	{
		const size_t pivot = median_of_five_index(arr+j, min(5, n-j), oper);
		oper.swap(&arr[i], &(arr+j)[pivot]);
	}
	return select_recursively(arr, max, oper);
}
