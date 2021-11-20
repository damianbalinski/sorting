#pragma once
#include "executor.hpp"

class cost_factor_executor : public executor
{
public:
	const char* name() const override { return "cost_factor"; }

	void execute(std::ostream& output, const generator* generator, const sorting* sorting, const invariants& invariants) const override;
};
