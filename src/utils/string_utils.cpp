#include "string_utils.hpp"
#include <cstdlib>
#include <cstring>

char* concat(const char* const str1, const char* const str2)
{
	char* const str = (char*)malloc(strlen(str1) + strlen(str2) + 1);
	strcpy(str, str1);
	strcat(str, str2);
	return str;
}
