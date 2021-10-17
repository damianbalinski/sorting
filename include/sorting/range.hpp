#pragma once

class range
{
public:
	range(const size_t begin, const size_t end, const size_t step):
		begin(begin), end(end), step(step) {}

	const size_t begin;
	const size_t end;
	const size_t step;
};
