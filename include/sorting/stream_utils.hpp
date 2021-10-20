#pragma once
#include "testing_row.hpp"
#include <iostream>

void save_row(std::ostream& ostream, const testing_row& row);

testing_row read_row(std::istream& istream, const testing_invariants& invariants);
