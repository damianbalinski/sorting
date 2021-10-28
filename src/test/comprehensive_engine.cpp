#include "comprehensive_engine.hpp"
#include "testing_engine.hpp"
#include "string_utils.hpp"
#include <fmt/format.h>
#include <fstream>
#include <sstream>

void comprehensive_engine::add(const sorting& sorting, const size_t repeats, const range& range)
{
	testing_groups.emplace_back(testing_group{sorting, repeats, range});
}

void comprehensive_engine::start() const
{
	for (const testing_group& group: testing_groups)
	{
		const std::string data = data_filename(group);
		const std::string results = results_filename(group);

		testing_engine engine{};
		engine.add(group.sorting, group.repeats, group.range);

		std::ofstream output{ data };
		engine.testing(output);
		output.close();

		std::ifstream input{ data, std::ios::in };
		std::ofstream output_results{ results };
		engine.statistics(input, output_results);
		input.close();
		output_results.close();

		std::remove(data.c_str());
	}
}

std::string comprehensive_engine::config() const
{
	std::ostringstream os;
	for (const testing_group& group : testing_groups)
	{
		os << group_config(group);
	}
	return os.str();
}

std::string comprehensive_engine::group_config(const testing_group& group) const
{
	std::ostringstream os;

	os << "{\n";
	os << fmt::format("\t'label': '{}',\n", sorting_pretty_name(group));
	os << fmt::format("\t'input': '{}',\n", results_filename(group));
	os << "},\n";

	return os.str();
}

std::string comprehensive_engine::data_filename(const testing_group& group) const
{
	return str_replace(fmt::format("{}\\{}_{}.tmp", directory, prefix, group.name), '\\', '/');
}

std::string comprehensive_engine::results_filename(const testing_group& group) const
{
	return str_replace(fmt::format("{}\\{}_{}.csv", directory, prefix, group.name), '\\', '/');
}

std::string comprehensive_engine::sorting_pretty_name(const testing_group& group) const
{
	return str_replace(group.name, '_', ' ');
}

