#pragma once
#include "configuration.hpp"
#include "unit.hpp"
#include <fstream>
#include <vector>

class configuration_resolver
{
public:
	configuration_resolver(std::ifstream& input);

	invariants get_invariants() const;

	std::string get_prefix() const;

	std::vector<unit> get_units() const;

private:
	cfg::configuration configuration;
};
