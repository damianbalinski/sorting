#pragma once
#include "comparator.hpp"

class operation 
{
public:
	operation(comparator& comp): comp(comp) {}
	bool eq(const int a, const int b) { return comp.eq(a, b); }
	bool ne(const int a, const int b) { return comp.ne(a, b); }
	bool gt(const int a, const int b) { return comp.gt(a, b); }
	bool ge(const int a, const int b) { return comp.ge(a, b); }
	bool lt(const int a, const int b) { return comp.lt(a, b); }
	bool le(const int a, const int b) { return comp.le(a, b); }

private:
	comparator& comp;
};
