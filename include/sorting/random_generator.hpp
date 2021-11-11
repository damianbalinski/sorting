#pragma once
#include "generator.hpp"

class random_generator : public generator
{
public:
	const char* name() const { return "random"; }

	int* operator()(const size_t n) const { return generate(n); }

private:
	static int* generate(size_t n);
};
