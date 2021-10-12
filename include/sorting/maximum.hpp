#pragma once
#include "comparator.hpp"

int maximum(const int* arr, size_t n, const comparator& comp);

size_t maximum_index(const int* arr, size_t n, const comparator& comp);
