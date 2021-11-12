#include "hard_merge_generator.hpp"

int* hard_merge_generator::generate(const size_t n)
{
	int* arr = new int[n];
	generate_recursively(arr, n);
	return arr;
}

void hard_merge_generator::generate_recursively(int* arr, size_t n)
{
	if (n == 1)
	{
		arr[0] = 0;
		return;
	}

	const size_t n1 = n/2;
	const size_t n2 = n - n1;
	generate_recursively(arr, n1);
	generate_recursively(arr+n1, n2);

	for (size_t i = 0; i < n1; i++) arr[i] = 2*arr[i];
	for (size_t i = n1; i < n; i++) arr[i] = 2*arr[i]+1;
}
