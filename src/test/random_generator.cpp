#include "random_generator.hpp"
#include "random.hpp"

int* random_generator::generate(const size_t n)
{
	set_random_seed();
	int* arr = new int[n];
	for (size_t i = 0; i < n; i++)
		arr[i] = rand();
	return arr;
}
