#pragma once

class swapper
{
public:
	void set_swapped(const bool new_swapped) { swapped = new_swapped; }

	bool get_swapped() { return swapped; }

	void swap(int* const a, int* const b)
	{
		const int temp = *a;
		*a = *b;
		*b = temp;
		swapped = true;
	}

private:
	bool swapped;
};
