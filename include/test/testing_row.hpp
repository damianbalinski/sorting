#pragma once

class testing_row
{
public:

	testing_row(const size_t id_global, const size_t id, const char* const sorting_name, const size_t n,
	const size_t comparisons, const size_t swaps, const size_t assigns):
		id_global(id_global), id(id), sorting_name(sorting_name), n(n),
		comparisons(comparisons), swaps(swaps), assigns(assigns) {}

	const size_t id_global;
	const size_t id;
	const char* const sorting_name;
	const size_t n;
	const size_t comparisons;
	const size_t swaps;
	const size_t assigns;
};
