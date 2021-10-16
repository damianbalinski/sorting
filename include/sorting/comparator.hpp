#pragma once

class comparator
{
public:
	virtual bool eq(int a, int b) const = 0;
	virtual bool ne(int a, int b) const = 0;
	virtual bool gt(int a, int b) const = 0;
	virtual bool ge(int a, int b) const = 0;
	virtual bool lt(int a, int b) const = 0;
	virtual bool le(int a, int b) const = 0;
};

class asc_comparator : public comparator
{
public:
	bool eq(const int a, const int b) const override { return a == b; }
	bool ne(const int a, const int b) const override { return a != b; }
	bool gt(const int a, const int b) const override { return a >  b; }
	bool ge(const int a, const int b) const override { return a >= b; }
	bool lt(const int a, const int b) const override { return a <  b; }
	bool le(const int a, const int b) const override { return a <= b; }
};

class desc_comparator : public comparator
{
public:
	bool eq(const int a, const int b) const override { return a == b; }
	bool ne(const int a, const int b) const override { return a != b; }
	bool gt(const int a, const int b) const override { return a <  b; }
	bool ge(const int a, const int b) const override { return a <= b; }
	bool lt(const int a, const int b) const override { return a >  b; }
	bool le(const int a, const int b) const override { return a >= b; }
};

class counting_asc_comparator : public comparator
{
public:
	counting_asc_comparator(size_t* const counter): counter(counter) {}
	bool eq(const int a, const int b) const override { (*counter)++; return a == b; }
	bool ne(const int a, const int b) const override { (*counter)++; return a != b; }
	bool gt(const int a, const int b) const override { (*counter)++; return a >  b; }
	bool ge(const int a, const int b) const override { (*counter)++; return a >= b; }
	bool lt(const int a, const int b) const override { (*counter)++; return a <  b; }
	bool le(const int a, const int b) const override { (*counter)++; return a <= b; }

private:
	size_t* const counter;
};

class counting_desc_comparator : public comparator
{
public:
	counting_desc_comparator(size_t* const counter): counter(counter) {}
	bool eq(const int a, const int b) const override { (*counter)++; return a == b; }
	bool ne(const int a, const int b) const override { (*counter)++; return a != b; }
	bool gt(const int a, const int b) const override { (*counter)++; return a <  b; }
	bool ge(const int a, const int b) const override { (*counter)++; return a <= b; }
	bool lt(const int a, const int b) const override { (*counter)++; return a >  b; }
	bool le(const int a, const int b) const override { (*counter)++; return a >= b; }

private:
	size_t* const counter;
};
