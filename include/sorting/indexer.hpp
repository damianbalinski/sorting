#pragma once

class indexer
{
public:
	const size_t max;

	indexer(const size_t max) : max(max) {}
	
	virtual size_t operator()(const int arr[], size_t i) const = 0;
};