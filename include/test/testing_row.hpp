#pragma once
#include "testing_invariants.hpp"
#include "testing_results.hpp"

class testing_row
{
public:

	testing_row(const testing_invariants& invariants, const testing_results& results):
		invariants(invariants), results(results) {}
		
	const testing_invariants& invariants;
	const testing_results& results;
};
