#pragma once

class swapper
{
public:
	virtual void swap(int* a, int* b) const = 0;
};

class simple_swapper : public swapper
{
public:
	void swap(int* const a, int* const b) const override
	{
		const int temp = *a;
		*a = *b;
		*b = temp;
	}
};
