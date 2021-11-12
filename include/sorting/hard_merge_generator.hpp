#pragma once
#include "generator.hpp"

class hard_merge_generator : public generator
{
public:
	const char* name() const { return "hard_merge"; }

	int* operator()(const size_t n) const override { return generate(n); }

private:
	static int* generate(size_t n);

	static void generate_recursively(int* arr, size_t n);
};
