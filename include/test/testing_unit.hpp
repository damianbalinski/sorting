#pragma once
#include "sorting.hpp"
#include "testing_invariants.hpp"

class testing_unit
{
public:
	testing_unit(const sorting& sorting, const size_t repeats, const size_t n):
		sorting(sorting), repeats(repeats), invariants(testing_invariants{ n, sorting.name() }) {}

	const sorting& sorting;
	const size_t repeats;
	const testing_invariants invariants;
};
