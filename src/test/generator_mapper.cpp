#include "generator_mapper.hpp"
#include "fail.hpp"
#include "random_generator.hpp"
#include "reversed_generator.hpp"

const generator* generator_mapper::map(const std::string& str)
{
	return allocate(str);
}

const generator* generator_mapper::allocate(const std::string& str)
{
	if (str == "random")	return new random_generator{};
	if (str == "reversed")	return new reversed_generator{};

	fail("Unrecognized generator");
}
