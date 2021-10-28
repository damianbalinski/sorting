#pragma once
#include "sorting.hpp"
#include "range.hpp"
#include "testing_group.hpp"
#include <vector>
#include <string>

class comprehensive_engine
{
public:
	comprehensive_engine(const char* const directory, const char* const prefix):
		directory(directory), prefix(prefix), testing_groups(std::vector<testing_group>{}) {}

	void add(const sorting& sorting, size_t repeats, const range& range);

	void start() const;

	std::string config() const;

private:
	const char* const directory;
	const char* const prefix;

	std::vector<testing_group> testing_groups;

	std::string group_config(const testing_group& group) const;

	std::string data_filename(const testing_group& group) const;

	std::string results_filename(const testing_group& group) const;

	std::string sorting_pretty_name(const testing_group& group) const;
};
