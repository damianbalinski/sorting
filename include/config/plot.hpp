#pragma once
#include "executor.hpp"
#include "sorting.hpp"
#include <vector>

namespace cfg
{
	struct plot
	{
		const executor* executor;
		std::vector<const sorting*> sortings;
	};

}
