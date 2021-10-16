#pragma once
#include "comparator.hpp"
#include "swapper.hpp"

class operation
{
public:
	operation(const comparator& comp, const swapper& swapper): comp(comp), swapper(swapper) {}
	bool eq(const int a, const int b) const { return comp.eq(a, b); }
	bool ne(const int a, const int b) const { return comp.ne(a, b); }
	bool gt(const int a, const int b) const { return comp.gt(a, b); }
	bool ge(const int a, const int b) const { return comp.ge(a, b); }
	bool lt(const int a, const int b) const { return comp.lt(a, b); }
	bool le(const int a, const int b) const { return comp.le(a, b); }
	void swap(int* const a, int* const b)   { swapper.swap(a, b);   }

private:
	const comparator& comp;
	const swapper& swapper;
};
