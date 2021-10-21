#pragma once

class testing_invariants
{
public:
	testing_invariants(const size_t n, const char* const sorting_name):
		n(n), sorting_name(sorting_name) {}

	const size_t n;
	const char* const sorting_name;
};
