#pragma once
#include <cstring>

inline int* __assign_many(int* const dest, const int* const src, size_t n)
{
	memcpy(dest, src, n * sizeof(int));
	return dest;
}

class assigner
{
public:
	virtual int assign(int dest) const = 0;
	virtual int* assign_many(int* dest, const int* src, size_t n) const = 0;
};

class simple_assigner : public assigner
{
public:
	int assign(const int dest) const { return dest; }
	int* assign_many(int* const dest, const int* const src, size_t n) const { return __assign_many(dest, src, n); }
};

class counting_assigner : public assigner
{
public:
	counting_assigner(size_t* const counter): counter(counter) {}
	int assign(const int dest) const { (*counter)++; return dest; }
	int* assign_many(int* const dest, const int* const src, size_t n) const { /*(*counter) += n;*/ return __assign_many(dest, src, n); }

private:
	size_t* const counter;
};
