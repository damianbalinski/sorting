#include "executor_mapper.hpp"
#include "fail.hpp"
#include "simple_executor.hpp"
#include "average_executor.hpp"
#include "density_executor.hpp"

const executor* executor_mapper::map(const std::string& str)
{
	return allocate(str);
}

const executor* executor_mapper::allocate(const std::string& str)
{
	if (str == "simple")	return new simple_executor{};
	if (str == "average")	return new average_executor{};
	if (str == "density")	return new density_executor{};

	fail("Unrecognized executor");
}
