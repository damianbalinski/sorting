#pragma once
#include <string>

std::string arr_to_string(const int* arr, size_t n);

std::string arr_to_string(const int* arr, size_t n, char separator, const char* color);

std::string arr_to_string_with_pivot(const int* arr, size_t n, size_t pivot);

std::string arr_to_string_with_pivot(const int* arr, size_t n, size_t pivot, char separator, const char* color, const char* pivot_color);

std::string arr_to_string_with_ids(const int* arr, size_t n);

size_t* arr_from(size_t a, size_t b);

size_t* arr_from(size_t a, size_t b, size_t c);

int** arr_of_ptr_from(int* a, int* b, int* c);
