#pragma once
#include "partition.hpp"
#include "pivot_selector.hpp"

class hoare_partition : public partition
{
public:
	hoare_partition(const pivot_selector* const selector) : partition(selector) {}

	size_t operator()(int arr[], const size_t n, const operation& oper) const override { return partitione(arr, n, oper); }

	size_t partitione(int arr[], size_t n, const operation& oper) const;
};
