#pragma once
#include "numeric_utils.hpp"

class swapper
{
public:
	virtual void swap(int* a, int* b) const = 0;

	virtual void swap_many(int* a, int* b, size_t n) const = 0;
};

class simple_swapper : public swapper
{
public:
	void swap(int* const a, int* const b) const override { safe_swap(a, b); }

	void swap_many(int* const a, int* const b, const size_t n) const { safe_swap_many(a, b, n); }
};

class counting_swapper : public swapper
{
public:
	counting_swapper(size_t* const counter): counter(counter) {}

	void swap(int* const a, int* const b) const override { (*counter)++; safe_swap(a, b); }

	void swap_many(int* const a, int* const b, const size_t n) const { (*counter)+=n; safe_swap_many(a, b, n); }

private:
	size_t* const counter;
};
