#include "array_utils.hpp"
#include <string>
#include <sstream>
#include <ctime>

std::string arr_to_string(int* const arr, const size_t n)
{
	return arr_to_string(arr, n, ' ');
}

std::string arr_to_string(int* const arr, const size_t n, const char separator)
{
	std::ostringstream os;
	for (size_t i = 0; i < n; i++) {
		os << arr[i] << separator;
	}
	return os.str();
}

std::string arr_to_string_with_ids(int* const arr, const size_t n)
{
	std::ostringstream os;
	for (size_t i = 0; i < n; i++) {
		os << i << " - " << arr[i] << std::endl;
	}
	return os.str();
}

int* arr_random_natural(const size_t n)
{
	srand(time(0));
	
	int* arr = new int[n];
	for (size_t i = 0; i < n; i++)
		arr[i] = rand();
	return arr;
}