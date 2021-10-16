#pragma once
#include "operation.hpp"
#include <string>

std::string arr_to_string(const int* arr, size_t n);

std::string arr_to_string(const int* arr, size_t n, char separator, const char* color);

std::string arr_to_string_with_pivot(const int* arr, size_t n, size_t pivot);

std::string arr_to_string_with_pivot(const int* arr, size_t n, size_t pivot, char separator, const char* color, const char* pivot_color);

std::string arr_to_string_with_ids(const int* arr, size_t n);

int* arr_random_natural(size_t n);

int* arr_random_in_range(size_t n, int max);

int* arr_copy(const int* src, size_t n);

int* arr_copy(int* dest, const int* src, size_t n);

size_t* arr_from(size_t a, size_t b);
