#pragma once
#include "results.hpp"
#include "sorting.hpp"
#include "invariants.hpp"
#include <ostream>

class executor
{
public:
	virtual const char* name() const = 0;

	virtual void execute(std::ostream& output, const sorting* sorting, const invariants& invariants) const = 0;

protected:
	results test(const sorting* sort, size_t n) const;
};
