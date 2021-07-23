#pragma once

class comparator
{
public:
	virtual bool eq(int a, int b) = 0;
	virtual bool ne(int a, int b) = 0;
	virtual bool gt(int a, int b) = 0;
	virtual bool ge(int a, int b) = 0;
	virtual bool lt(int a, int b) = 0;
	virtual bool le(int a, int b) = 0;
};

class asc_comparator : public comparator
{
public:
	bool eq(const int a, const int b) override { return a == b; }
	bool ne(const int a, const int b) override { return a != b; }
	bool gt(const int a, const int b) override { return a >  b; }
	bool ge(const int a, const int b) override { return a >= b; }
	bool lt(const int a, const int b) override { return a <  b; }
	bool le(const int a, const int b) override { return a <= b; }
};

class desc_comparator : public comparator
{
public:
	bool eq(const int a, const int b) override { return a == b; }
	bool ne(const int a, const int b) override { return a != b; }
	bool gt(const int a, const int b) override { return a <  b; }
	bool ge(const int a, const int b) override { return a <= b; }
	bool lt(const int a, const int b) override { return a >  b; }
	bool le(const int a, const int b) override { return a >= b; }
};
