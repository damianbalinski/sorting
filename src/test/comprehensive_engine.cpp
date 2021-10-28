#include "comprehensive_engine.hpp"
#include "testing_engine.hpp"
#include "constants.hpp"
#include <fmt/format.h>
#include <string>
#include <fstream>

void comprehensive_engine::add(const sorting& sorting, const size_t repeats, const range& range)
{
	testing_groups.emplace_back(testing_group{sorting, repeats, range});
}

void comprehensive_engine::start(const char* const filename_prefix)
{
	for (testing_group& group: testing_groups)
	{
		std::string data = fmt::format("{}\\{}_{}.tmp", TEST_DIRECTORY, filename_prefix, group.sorting.name());
		std::string results = fmt::format("{}\\{}_{}.csv", TEST_DIRECTORY, filename_prefix, group.sorting.name());

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
