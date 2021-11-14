#pragma once
#include "pivot_selector.hpp"

class median_of_medians_of_three_pivot_selector : public pivot_selector
{
public:
	const char* name() const override { return "_median_of_medians_of_three_pivot_selector"; }

	void operator()(int arr[], const size_t n, const size_t pos, const operation& oper) const override { select(arr, n, pos, oper); }

private:
	static void select(int arr[], size_t n, size_t pos, const operation& oper);

	static size_t select_recursively(int arr[], size_t n, const operation& oper);

	static size_t sample(const size_t i, const size_t n) { return (i*n) / 3; }
};
