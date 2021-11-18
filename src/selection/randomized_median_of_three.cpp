#include "randomized_median_of_three.hpp"
#include "median_of_three.hpp"
#include "maximum.hpp"
#include "random.hpp"

size_t randomized_median_of_three_index(int arr[], const size_t n, const operation& oper)
{
	if (n == 1) return 0;
	if (n == 2) return maximum_index(arr, 2, oper);

	set_random_seed();
	const size_t bx = 1 + rand() % (n - 2);
	const size_t ax = rand() % bx;
	const size_t cx = bx + 1 + rand() % (n - bx - 1);
	return median_of_three_index(arr, ax, bx, cx, oper);
}