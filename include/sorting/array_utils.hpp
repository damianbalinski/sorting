#pragma once
#include <string>

std::string arr_to_string(int* arr, size_t n);

std::string arr_to_string(int* arr, size_t n, char separator);

std::string arr_to_string_with_ids(int* arr, size_t n);

int* arr_random_natural(size_t n);
