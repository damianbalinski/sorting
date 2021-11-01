#include "assert_stream.hpp"
#include "colors.hpp"

inline void __pretty_assertion(const std::string& msg)
{
	std::cerr << "assertion failed" << std::endl;
	std::cerr << RED << msg << WHITE << std::endl;
	std::cerr << "program is aborted" << std::endl;
	abort();
}

void __check_istream_open(const std::istream& input)
{
	if (input.fail())
	{
		__pretty_assertion("Input stream is not open");
	}
}

void __check_ostream_open(const std::ostream& output)
{
	if (output.fail())
	{
		__pretty_assertion("Output stream is not open");
	}
}
