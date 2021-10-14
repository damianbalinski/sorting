#include "array_utils.hpp"
#include <string>
#include <sstream>
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

std::string arr_to_string(const int* const arr, const size_t n)
{
	return arr_to_string(arr, n, ' ');
}

std::string arr_to_string(const int* const arr, const size_t n, const char separator)
{
	std::ostringstream os;
	for (size_t i = 0; i < n; i++) {
		os << arr[i] << separator;
	}
	return os.str();
}

std::string arr_to_string_with_ids(const int* const arr, const size_t n)
{
	std::ostringstream os;
	for (size_t i = 0; i < n; i++) {
		os << i << " - " << arr[i] << std::endl;
	}
	return os.str();
}

int* arr_random_natural(const size_t n)
{
	set_random_seed();
	
	int* arr = new int[n];
	for (size_t i = 0; i < n; i++)
		arr[i] = rand();
	return arr;
}

int* arr_random_in_range(const size_t n, const int max)
{
	set_random_seed();

	int* arr = new int[n];
	for (size_t i = 0; i < n; i++)
		arr[i] = rand() % max;
	return arr;
}

int* arr_copy(const int* const src, const size_t n)
{
	int* const dest = new int[n];
	memcpy(dest, src, n*sizeof(int));
	return dest;
}

int* arr_copy(int* const dest, const int* const src, const size_t n)
{
	memcpy(dest, src, n*sizeof(int));
	return dest;
}

size_t* arr_from(const size_t a, const size_t b)
{
	size_t* const arr = new size_t[2];
	arr[0] = a;
	arr[1] = b;
	return arr;
}
