#pragma once
#include "range.hpp"
#include "sorting.hpp"
#include "testing_unit.hpp"
#include "testing_result.hpp"
#include "testing_row.hpp"
#include <ostream>
#include <vector>

class testing_engine
{
public:
	testing_engine(std::ostream& ostream):
		ostream(ostream), testing_units(std::vector<testing_unit>{}) {}

	void add(const sorting& sorting, size_t repeats, size_t n);

	void add(const sorting& sorting, size_t repeats, const range& range);

	void start() const;

private:
	std::ostream& ostream;
	std::vector<testing_unit> testing_units;

	testing_row test(const testing_unit& unit, size_t id_global, size_t id) const;

	testing_result test_sorting(const sorting& sort, size_t n) const;

};
