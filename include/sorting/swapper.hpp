#pragma once

inline void __swap(int* const a, int* const b)
{
	const int temp = *a;
	*a = *b;
	*b = temp;
}

inline void __swap_many(int* const a, int* const b, const size_t n)
{
	for (size_t i = 0; i < n; i++) __swap(a+i, b+i);
}

class swapper
{
public:
	virtual void swap(int* a, int* b) const = 0;

	virtual void swap_many(int* a, int* b, size_t n) const = 0;
};

class simple_swapper : public swapper
{
public:
	void swap(int* const a, int* const b) const override { __swap(a, b); }

	void swap_many(int* const a, int* const b, const size_t n) const { __swap_many(a, b, n); }
};

class counting_swapper : public swapper
{
public:
	counting_swapper(size_t* const counter): counter(counter) {}

	void swap(int* const a, int* const b) const override { (*counter)++; __swap(a, b); }

	void swap_many(int* const a, int* const b, const size_t n) const { (*counter)+=n; __swap_many(a, b, n); }

private:
	size_t* const counter;
};
