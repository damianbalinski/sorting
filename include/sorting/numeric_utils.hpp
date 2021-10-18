#pragma once

inline size_t log2(const size_t n)
{
	return log2(n*1.0);
}

inline size_t safe_mean_of_two(const size_t a, const size_t b)
{
	return a + (b - a) / 2;
}

inline size_t max(const size_t a, const size_t b)
{
	return (a>b) ? a : b;
}
