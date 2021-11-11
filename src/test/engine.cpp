#include "engine.hpp"
#include "configuration_resolver.hpp"
#include "constants.hpp"
#include <fstream>
#include <fmt/format.h>

engine::engine()
{
	std::ifstream input{ filename_config(), std::ios::in };
	const configuration_resolver resolver{input};
	invariants = resolver.get_invariants();
	prefix = resolver.get_prefix();
	units = resolver.get_units();
}

void engine::test() const
{
	for(const unit& unit: units)
	{
		const executor* const executor = unit.executor;
		const generator* const generator = unit.generator;
		const sorting* const sorting = unit.sorting;

		std::ofstream output{ filename_test(executor, generator, sorting) };
		executor->execute(output, generator, sorting, invariants);
		output.close();
	}
}

std::string engine::filename_config() const
{
	return fmt::format("{}\\config.json", CONFIG_DIRECTORY);
}

std::string engine::filename_test(const executor* const executor, const generator* generator, const sorting* const sorting) const
{
	return fmt::format("{}\\{}_{}_{}_{}.csv", TEST_DIRECTORY, prefix, executor->name(), generator->name(), sorting->name());
}
