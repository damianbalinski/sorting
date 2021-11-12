#include "generator_mapper.hpp"
#include "fail.hpp"
#include "random_generator.hpp"
#include "reversed_generator.hpp"
#include "almost_sorted_generator.hpp"
#include "sorted_generator.hpp"
#include "hard_merge_generator.hpp"

const generator* generator_mapper::map(const std::string& str)
{
	return allocate(str);
}

const generator* generator_mapper::allocate(const std::string& str)
{
	if (str == "random")		return new random_generator{};
	if (str == "reversed")		return new reversed_generator{};
	if (str == "sorted")		return new sorted_generator{};
	if (str == "almost_sorted")	return new almost_sorted_generator{};
	if (str == "hard_merge")	return new hard_merge_generator{};

	fail("Unrecognized generator");
}
