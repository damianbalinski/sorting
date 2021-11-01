#include "executor_mapper.hpp"
#include "fail.hpp"
#include "average_executor.hpp"
#include "simple_executor.hpp"

const executor* executor_mapper::map(const std::string& str)
{
	return allocate(str);
}

const executor* executor_mapper::allocate(const std::string& str)
{
	if (str == "simple")	return new simple_executor{};
	if (str == "average")	return new average_executor{};

	fail("Unrecognized executor");
}
