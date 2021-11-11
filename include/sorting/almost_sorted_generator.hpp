#pragma once
#include "generator.hpp"

class almost_sorted_generator : public generator
{
public:
	const char* name() const { return "almost_sorted"; }

	int* operator()(const size_t n) const { return generate(n); }

private:
	static int* generate(size_t n);
};
