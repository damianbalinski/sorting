#pragma once
#include "executor.hpp"

class simple_executor : public executor
{
public:
	simple_executor(const sorting& sort, size_t rep, const range& rng) :
		executor{ sort, rep, rng } {}

	void execute(std::ostream& output) const override;
};
