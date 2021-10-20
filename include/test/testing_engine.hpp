#pragma once
#include "range.hpp"
#include "sorting.hpp"
#include "testing_unit.hpp"
#include "testing_results.hpp"
#include "testing_row.hpp"
#include <ostream>
#include <vector>

class testing_engine
{
public:
	testing_engine(): testing_units(std::vector<testing_unit>{}) {}

	void add(const sorting& sorting, size_t repeats, size_t n);

	void add(const sorting& sorting, size_t repeats, const range& range);

	void testing(std::ostream& ostream) const;

	void statistics(std::istream& istream) const;

private:
	std::vector<testing_unit> testing_units;

	testing_results test(const sorting& sort, size_t n) const;

};
