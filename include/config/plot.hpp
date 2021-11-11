#pragma once
#include "executor.hpp"
#include "unit_test.hpp"
#include <vector>

namespace cfg
{
	struct plot
	{
		const executor* executor;
		std::vector<unit_test> tests;
	};

}
