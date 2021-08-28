#pragma once

class indexer
{
public:
	virtual size_t operator()(const int arr[], size_t i) const = 0;
};