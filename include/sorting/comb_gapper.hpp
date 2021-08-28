#pragma once
#include "gapper.hpp"

class comb_gapper : public gapper
{
public:
	size_t operator()(const size_t prev_gap) const override { return gap(prev_gap); }

private:
	static size_t gap(const size_t prev_gap) { return prev_gap * 10 / 13; }
};
