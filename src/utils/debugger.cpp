#include "debugger.hpp"
#include "array_utils.hpp"
#include "colors.hpp"
#include <iostream>
#include <sstream>

static const int* arr_root = nullptr;
static size_t n_root = 0;

void __dbg_arr_init(const int* const arr, const size_t n)
{
	arr_root = arr;
	n_root = n;
}

void __dbg_arr_print_step(const int* const arr, const size_t n)
{
	std::cout << __dbg_arr_step(arr, n) << std::endl;
}

void __dbg_arr_print_pivot(const int* const arr, const size_t n, const size_t pivot)
{
	std::cout << __dbg_arr_pivot(arr, n, pivot) << std::endl;
}

std::string __dbg_arr_step(const int* const arr, const size_t n)
{
	std::ostringstream os;
	const size_t n1 = ((size_t)arr - (size_t)arr_root) / sizeof(int);
	const int* arr1 = arr_root;

	const size_t n3 = n_root - n - n1;
	const int* arr3 = arr+n;

	os << arr_to_string(arr1, n1, ' ', WHITE);
	os << arr_to_string(arr, n, ' ', BLUE);
	os << arr_to_string(arr3, n3, ' ', WHITE);
	return os.str();
}

std::string __dbg_arr_pivot(const int* const arr, const size_t n, const size_t pivot)
{
	std::ostringstream os;
	const size_t n1 = ((size_t)arr - (size_t)arr_root) / sizeof(int);
	const int* arr1 = arr_root;

	const size_t n3 = n_root - n - n1;
	const int* arr3 = arr + n;

	os << arr_to_string(arr1, n1, ' ', WHITE);
	os << arr_to_string_with_pivot(arr, n, pivot, ' ', BLUE, PURPLE);
	os << arr_to_string(arr3, n3, ' ', WHITE);
	return os.str();
}
