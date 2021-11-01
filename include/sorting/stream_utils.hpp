#pragma once
#include "testing_identifier.hpp"
#include "testing_results.hpp"
#include "results.hpp"
#include "testing_invariants.hpp"
#include <iostream>
#include <string>

void save_row(std::ostream& ostream, const testing_invariants& invariants, const testing_results& results, const testing_identifier& identifier);

void save_results(std::ostream& ostream, const testing_invariants& invariants, const testing_results& results);

testing_results read_results(std::istream& istream, const testing_identifier& identifier);

void save_results(std::ostream& output, size_t n, const results& results);

std::string read_file(std::istream& input);
