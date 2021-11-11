#pragma once
#include "executor.hpp"

class simple_executor : public executor
{
public:
	const char* name() const override { return "simple"; }

	void execute(std::ostream& output, const generator* generator, const sorting* sorting, const invariants& invariants) const override;
};
