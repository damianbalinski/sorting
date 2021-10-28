#include "string_utils.hpp"
#include <algorithm>

std::string str_replace(std::string str, char from, char to)
{
	std::replace(str.begin(), str.end(), from, to);
	return str;
}
