#include "sorted_generator.hpp"

int* sorted_generator::generate(const size_t n)
{
	int* arr = new int[n];
	for (size_t i = 0; i < n; i++) arr[i] = i;
	return arr;
}
