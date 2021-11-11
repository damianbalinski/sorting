#include "generator.hpp"

class reversed_generator : public generator
{
public:
	const char* name() const { return "reversed"; }

	int* operator()(const size_t n) const { return generate(n); }

private:
	static int* generate(size_t n);
};
