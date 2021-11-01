#pragma once
#include "colors.hpp"
#include <iostream>

inline void fail(const std::string& msg)
{
	std::cerr << "program failed" << std::endl;
	std::cerr << RED << msg << WHITE << std::endl;
	std::cerr << "program is aborted" << std::endl;
	abort();
}
