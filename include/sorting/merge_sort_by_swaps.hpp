#pragma once
#include "sorting.hpp"

class merge_sort_by_swaps : public sorting
{
public:
	static void sort(int arr[], int buff[], size_t n, const operation& oper);

	static void merge(int arr[], int buff[], size_t n1, size_t n2, const operation& oper);
};
