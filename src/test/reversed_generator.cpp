#include "reversed_generator.hpp"

int* reversed_generator::generate(const size_t n)
{
	int* arr = new int[n];
	for (size_t i = 0; i < n; i++)
		arr[i] = n-i-1;
	return arr;
}
