#include "array_utils.hpp"
#include <string>
#include <sstream>
#include <ctime>

int __static_srand()
{
	srand(time(NULL));
	return 0;
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
	static int __ignored = __static_srand();
	
	int* arr = new int[n];
	for (size_t i = 0; i < n; i++)
		arr[i] = rand();
	return arr;
}

int* arr_copy(const int* const src, const size_t n)
{
	int* const dest = new int[n];
	memcpy(dest, src, n*sizeof(int));
	return dest;
}

void arr_copy(int* const dest, const int* const src, const size_t n)
{
	memcpy(dest, src, n*sizeof(int));
}

size_t* arr_from(const size_t a, const size_t b)
{
	size_t* const arr = new size_t[2];
	arr[0] = a;
	arr[1] = b;
	return arr;
}