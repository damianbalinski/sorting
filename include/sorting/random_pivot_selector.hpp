#pragma once
#include "pivot_selector.hpp"

class random_pivot_selector : public pivot_selector
{
public:
	const char* name() const override { return "_random_pivot_selector"; }

	void operator()(int arr[], const size_t n, const size_t pos, const operation& oper) const override { select(arr, n, pos, oper); }

private:
	static void select(int arr[], size_t n, size_t pos, const operation& oper);
};