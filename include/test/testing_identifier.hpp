#pragma once

class testing_identifier
{
public:
	testing_identifier(const size_t id_global, const size_t id):
		id_global(id_global), id(id) {}

	const size_t id_global;
	const size_t id;
};
