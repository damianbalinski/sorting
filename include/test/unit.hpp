#pragma once
#include "executor.hpp"
#include "sorting.hpp"
#include <cstring>

class unit
{
public:
	unit(const executor* const executor, const sorting* const sorting):
		executor(executor), sorting(sorting) {}

	const executor* executor;
	const sorting* sorting;

	bool operator==(const unit& other) const {
		return strcmp(executor->name(), other.executor->name()) == 0
			&& strcmp(sorting->name(), other.sorting->name()) == 0;
	}
};
