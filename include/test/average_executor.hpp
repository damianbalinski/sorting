#pragma once
#include "executor.hpp"

class average_executor : public executor
{
public:
	void execute(std::ostream& output, const sorting& sorting, const invariants& invariants) const override;
};
