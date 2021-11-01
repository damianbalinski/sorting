#pragma once
#include "executor.hpp"
#include "invariants.hpp"
#include "sorting.hpp"
#include <vector>

namespace cfg
{
	struct plot
	{
		const executor* executor;
		invariants invariants;
		std::vector<const sorting*> sortings;
	};

}
