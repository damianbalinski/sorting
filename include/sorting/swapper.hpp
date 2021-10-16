#pragma once
#include "swap.hpp"

class swapper
{
public:
	void operator()(int* const a, int* const b) const { swap(a, b); }
};
