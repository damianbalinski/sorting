#include "random_pivot_selector.hpp"
#include "random.hpp"

void random_pivot_selector::select(int arr[], const size_t n, const size_t pos, const operation& oper)
{
	set_random_seed();
	const size_t pivot = rand() % n;
	swap_pivot_in_position(arr, pivot, pos, oper);
}
