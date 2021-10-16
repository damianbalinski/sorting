#pragma once
#include "comparator.hpp"

class operation
{
public:
	operation(const comparator& comp): comp(comp) {}
	bool eq(int a, int b) const { return comp.eq(a, b); }
	bool ne(int a, int b) const { return comp.ne(a, b); }
	bool gt(int a, int b) const { return comp.gt(a, b); }
	bool ge(int a, int b) const { return comp.ge(a, b); }
	bool lt(int a, int b) const { return comp.lt(a, b); }
	bool le(int a, int b) const { return comp.le(a, b); }

private:
	const comparator& comp;
};
