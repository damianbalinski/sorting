#include "array_utils.hpp"
#include "colors.hpp"
#include <sstream>

std::string arr_to_string(const int* const arr, const size_t n)
{
	return arr_to_string(arr, n, ' ', WHITE);
}

std::string arr_to_string(const int* const arr, const size_t n, const char separator, const char* const color)
{
	std::ostringstream os;
	os << color;
	for (size_t i = 0; i < n; i++) {
		os << arr[i] << separator;
	}
	os << WHITE;
	return os.str();
}

std::string arr_to_string_with_pivot(const int* const arr, const size_t n, const size_t pivot)
{
	return arr_to_string_with_pivot(arr, n, pivot, ' ', WHITE, PURPLE);
}

std::string arr_to_string_with_pivot(const int* const arr, const size_t n, const size_t pivot, const char separator, const char* const color, const char* const pivot_color)
{
	std::ostringstream os;
	os << arr_to_string(arr, pivot, separator, color);
	os << pivot_color << arr[pivot] << color << separator;
	os << arr_to_string(arr+pivot+1, n-pivot-1, separator, color);
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

size_t* arr_from(const size_t a, const size_t b)
{
	size_t* const arr = new size_t[2];
	arr[0] = a;
	arr[1] = b;
	return arr;
}

size_t* arr_from(const size_t a, const size_t b, const size_t c)
{
	size_t* const arr = new size_t[3];
	arr[0] = a;
	arr[1] = b;
	arr[2] = c;
	return arr;
}

int** arr_of_ptr_from(int* const a, int* const b, int* const c)
{
	int** const arr = new int*[3];
	arr[0] = a;
	arr[1] = b;
	arr[2] = c;
	return arr;
}
