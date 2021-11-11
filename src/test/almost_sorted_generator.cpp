#include "almost_sorted_generator.hpp"
#include "numeric_utils.hpp"
#include "random.hpp"

int* almost_sorted_generator::generate(const size_t n)
{
	set_random_seed();

	int* arr = new int[n];
	for (size_t i = 0; i < n; i++) arr[i] = i;

	for (size_t i = 0; i < n/4; i++)
	{
		const size_t a1 = rand()%(n-1);
		const size_t a2 = a1 + rand()%(n-a1);
		safe_swap(&arr[a1], &arr[a2]);
	}
	return arr;
}
