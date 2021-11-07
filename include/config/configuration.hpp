#pragma once
#include "plot.hpp"
#include <vector>
#include <string>

namespace cfg
{
	struct configuration
	{
		std::string prefix;
		std::vector<plot> plots;
		invariants invariants;
	};
}
