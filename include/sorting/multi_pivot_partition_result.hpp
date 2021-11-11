#pragma once

struct multi_pivot_partition_result
{
	const size_t* pivots;
	const size_t* ns;
	int** arrs;
};
