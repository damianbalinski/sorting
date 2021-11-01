#include "engine.hpp"
#include "configuration_parser.hpp"
#include "constants.hpp"
#include <fstream>
#include <nlohmann/json.hpp>
#include <fmt/format.h>

engine::engine()
{
	std::ifstream input{ filename_config(), std::ios::in };
	nlohmann::json j;
	input >> j;
	configuration = j.get<cfg::configuration>();
}

void engine::test() const
{
	for(const cfg::plot& plot: configuration.plots)
	{
		test_single_plot(plot);
	}
}

void engine::test_single_plot(const cfg::plot& plot) const
{
	for (const sorting* sorting: plot.sortings)
	{
		const executor* const executor = plot.executor;
		const invariants& invariants = plot.invariants;

		std::ofstream output{ filename_test(executor, sorting) };
		executor->execute(output, sorting, invariants);
		output.close();
	}
}

std::string engine::filename_config() const
{
	return fmt::format("{}\\config.json", CONFIG_DIRECTORY);
}

std::string engine::filename_test(const executor* const executor, const sorting* const sorting) const
{
	return fmt::format("{}\\{}_{}_{}.csv", TEST_DIRECTORY, configuration.prefix, executor->name(), sorting->name());
}
