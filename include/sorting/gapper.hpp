#pragma once

class gapper
{
public:
	virtual size_t operator()(size_t prev_gap) const = 0;
};
