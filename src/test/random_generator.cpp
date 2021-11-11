#include "random_generator.hpp"
#include <cstdlib>
#include <ctime>

int __random_seed()
{
	srand(time(nullptr));
	return 0;
}

void set_random_seed()
{
	static int __ignored = __random_seed();
}

int* random_generator::generate(const size_t n)
{
	set_random_seed();
	int* arr = new int[n];
	for (size_t i = 0; i < n; i++)
		arr[i] = rand();
	return arr;
}
