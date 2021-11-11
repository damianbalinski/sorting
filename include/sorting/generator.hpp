#pragma once

class generator
{
public:
	virtual const char* name() const = 0;

	virtual int* operator()(size_t n) const = 0;
};
