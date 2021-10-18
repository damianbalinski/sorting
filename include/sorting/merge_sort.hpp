#pragma once
#include "sorting.hpp"

class merge_sort : public sorting
{
public:
	const char* name() const override { return "merge_sort"; }

	void operator()(int arr[], const size_t n, const operation& oper) const override { sort(arr, n, oper); }

private:
	static void sort(int arr[], size_t n, const operation& oper);
	
	static void merge(int arr[], int buff[], size_t n1, size_t n2, const operation& oper);
};
