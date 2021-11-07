#pragma once
#include "executor.hpp"
#include "sorting.hpp"

class unit
{
public:
	unit(const executor* const executor, const sorting* const sorting):
		executor(executor), sorting(sorting) {}

	const executor* executor;
	const sorting* sorting;

	bool operator==(const unit& other) const {
		return executor->name() == other.executor->name() &&
			sorting->name() == other.sorting->name();
	}
};
