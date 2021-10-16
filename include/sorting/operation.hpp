#pragma once
#include "comparator.hpp"
#include "swapper.hpp"
#include "assigner.hpp"

class operation
{
public:
	operation(const comparator& comp, const swapper& swapper, const assigner& assigner):
		comp(comp), swapper(swapper), assigner(assigner) {}

	bool eq(const int a, const int b) const { return comp.eq(a, b); }
	bool ne(const int a, const int b) const { return comp.ne(a, b); }
	bool gt(const int a, const int b) const { return comp.gt(a, b); }
	bool ge(const int a, const int b) const { return comp.ge(a, b); }
	bool lt(const int a, const int b) const { return comp.lt(a, b); }
	bool le(const int a, const int b) const { return comp.le(a, b); }

	void swap(int* const a, int* const b) const { swapper.swap(a, b); }
	void swap_in_order(int* const a, int* const b) const { if (comp.gt(*a, *b)) swapper.swap(a, b); }
	void arr_swap(int* const a, int* const b, const size_t n) const { swapper.swap_many(a, b, n); }

	int assign(int dest) const { return assigner.assign(dest); }
	int* arr_copy(int* const dest, const int* const src, const size_t n) const { return assigner.assign_many(dest, src, n); }

private:
	const comparator& comp;
	const swapper& swapper;
	const assigner& assigner;
};
