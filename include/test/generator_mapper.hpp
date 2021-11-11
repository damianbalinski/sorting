#pragma once
#include "generator.hpp"
#include <string>

class generator_mapper
{
public:
	static const generator* map(const std::string& str);

private:
	static const generator* allocate(const std::string& str);
};
