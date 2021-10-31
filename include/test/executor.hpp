#pragma once
#include "results.hpp"
#include "sorting.hpp"
#include "range.hpp"
#include <ostream>

class executor
{
public:
	executor(const sorting& sort, size_t rep, const range& rng):
		sort(sort), rep(rep), rng(rng) {}

	virtual void execute(std::ostream& output) const = 0;

	results test(const sorting& sort, size_t n) const;

protected:
	const sorting& sort;
	const size_t rep;
	const range& rng;
};
