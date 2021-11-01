#pragma once
#include "executor.hpp"

class average_executor : public executor
{
public:
	const char* name() const override { return "average"; }

	void execute(std::ostream& output, const sorting* sorting, const invariants& invariants) const override;
};
