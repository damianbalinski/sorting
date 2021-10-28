#pragma once
#include "sorting.hpp"
#include "range.hpp"
#include "testing_group.hpp"
#include <vector>

class comprehensive_engine
{
public:
	comprehensive_engine() : testing_groups(std::vector<testing_group>{}) {}

	void add(const sorting& sorting, size_t repeats, const range& range);

	void start(const char* filename_prefix);

private:
	std::vector<testing_group> testing_groups;
};
