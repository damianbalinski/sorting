#pragma once

inline void __swap(int* const a, int* const b)
{
	const int temp = *a;
	*a = *b;
	*b = temp;
}

class swapper
{
public:
	virtual void swap(int* a, int* b) const = 0;
};

class simple_swapper : public swapper
{
public:
	void swap(int* const a, int* const b) const override { __swap(a, b); }
};

class counting_swapper : public swapper
{
public:
	counting_swapper(size_t* const counter): counter(counter) {}

	void swap(int* const a, int* const b) const override { (*counter)++; __swap(a, b); }

private:
	size_t* const counter;
};
