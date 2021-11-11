#pragma once
#include "executor.hpp"
#include "generator.hpp"
#include "sorting.hpp"
#include <cstring>

class unit
{
public:
	unit(const executor* const executor, const generator* const generator, const sorting* const sorting):
		executor(executor), generator(generator), sorting(sorting) {}

	const executor* executor;
	const generator* generator;
	const sorting* sorting;

	bool operator==(const unit& other) const {
		return strcmp(executor->name(), other.executor->name()) == 0
			&& strcmp(generator->name(), other.generator->name()) == 0
			&& strcmp(sorting->name(), other.sorting->name()) == 0;
	}
};
