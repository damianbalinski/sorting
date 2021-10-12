#pragma once
#include "comparator.hpp"

int minimum(const int* arr, size_t n, const comparator& comp);

size_t minimum_index(const int* arr, size_t n, const comparator& comp);
