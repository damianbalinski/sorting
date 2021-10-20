#pragma once

class testing_invariants
{
public:
	testing_invariants(const size_t id_global, const size_t id,
	const size_t n, const char* const sorting_name):
		id_global(id_global), id(id), n(n), sorting_name(sorting_name) {}

	const size_t id_global;
	const size_t id;
	const size_t n;
	const char* const sorting_name;
};
