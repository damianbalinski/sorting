#pragma once
#include "executor.hpp"

class density_executor : public executor
{
public:
	const char* name() const override { return "density"; }

	void execute(std::ostream& output, const sorting* sorting, const invariants& invariants) const override;
};
