#pragma once
#include "executor.hpp"

class simple_executor : public executor
{
public:
	void execute(std::ostream& output, const sorting& sorting, const invariants& invariants) const override;
};
