#include "configuration_resolver.hpp"
#include "configuration_parser.hpp"
#include "plot.hpp"
#include <nlohmann/json.hpp>
#include <iostream>

configuration_resolver::configuration_resolver(std::ifstream& input)
{
	nlohmann::json j;
	input >> j;
	configuration = j.get<cfg::configuration>();
}

invariants configuration_resolver::get_invariants() const
{
	return configuration.invariants;
}

std::string configuration_resolver::get_prefix() const
{
	return configuration.prefix;
}

std::vector<unit> configuration_resolver::get_units() const
{
	std::vector<unit> units{};
	for (const cfg::plot& plot: configuration.plots)
	{
		for (const sorting* sorting: plot.sortings)
		{
			const unit u{plot.executor, sorting};
			if (std::find(units.begin(), units.end(), u) == units.end()) {
				units.push_back(u);
			}
		}
	}
	return units;
}
