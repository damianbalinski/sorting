#pragma once
#include "configuration.hpp"
#include "plot.hpp"
#include <string>

class engine
{
public:
	engine();

	void test() const;

private:
	cfg::configuration configuration;

	void test_single_plot(const cfg::plot& plot) const;

	std::string filename_config() const;

	std::string filename_test(const executor* executor, const sorting* sorting) const;
};
