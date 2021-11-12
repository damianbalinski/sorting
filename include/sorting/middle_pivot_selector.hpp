#pragma once
#include "pivot_selector.hpp"

class middle_pivot_selector : public pivot_selector
{
public:
	const char* name() const override { return "_middle_pivot_selector"; }

	size_t operator()(int arr[], const size_t n, const operation& oper) const override { return select(arr, n, oper); }

private:
	static size_t select(int arr[], size_t n, const operation& oper);
};