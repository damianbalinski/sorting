#pragma once
#include "unit.hpp"
#include <vector>
#include <string>

class engine
{
public:
	engine();

	void test() const;

private:
	invariants invariants;
	std::string prefix;
	std::vector<unit> units;

	std::string filename_config() const;

	std::string filename_test(const executor* executor, const generator* generator, const sorting* sorting) const;
};
