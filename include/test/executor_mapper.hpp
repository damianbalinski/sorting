#pragma once
#include "executor.hpp"
#include <string>

class executor_mapper
{
public:
	static const executor* map(const std::string& str);

private:
	static const executor* allocate(const std::string& str);
};
