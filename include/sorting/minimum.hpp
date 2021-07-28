#pragma once
#include "comparator.hpp"

int minimum(int* arr, size_t n, const comparator& comp);

size_t minimum_index(int* arr, size_t n, const comparator& comp);
