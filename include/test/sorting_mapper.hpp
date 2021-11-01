#pragma once
#include "sorting.hpp"
#include <string>

class sorting_mapper
{
public:
	static const sorting* map(const std::string& str);

private:
	static const sorting* allocate(const std::string& str);
};
