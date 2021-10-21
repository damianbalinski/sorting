#pragma once
#include "testing_identifier.hpp"
#include "testing_results.hpp"
#include "testing_invariants.hpp"
#include <iostream>

void save_row(std::ostream& ostream, const testing_identifier& identifier, const testing_results& results, const testing_invariants& invariants);

void save_results(std::ostream& ostream, const testing_results& results, const testing_invariants& invariants);

testing_results read_results(std::istream& istream, const testing_identifier& identifier);
