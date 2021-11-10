#pragma once

struct partition_result
{
	const size_t pivot;
	const size_t n1;
	const size_t n2;
	int* arr1;
	int* arr2;
};
