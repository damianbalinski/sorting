#pragma once
#include "operation.hpp"

#ifndef NDEBUG_ARR
	#define check_arr_sorted(ARR, N, OPER)				__check_arr_sorted(ARR, N, OPER)
	#define check_arr_partitioned(ARR, N, PIVOT, OPER)	__check_arr_partitioned(ARR, N, PIVOT, OPER)
	#define check_arr_is_binary_max_heap(ARR, N, OPER)	__check_arr_is_binary_max_heap(ARR, N, OPER)
	#define check_arr_equal(ARR1, ARR2, N, OPER)		__check_arr_equal(ARR1, ARR2, N, OPER)
#else
	#define check_arr_sorted(ARR, N, OPER)
	#define check_arr_partitioned(ARR, N, PIVOT, OPER)
	#define check_arr_is_binary_max_heap(ARR, N, OPER)
	#define check_arr_equal(ARR1, ARR2, N, OPER)
#endif

void __check_arr_sorted(const int* arr, size_t n, const operation& oper);

void __check_arr_partitioned(const int* arr, size_t n, size_t pivot, const operation& oper);

void __check_arr_is_binary_max_heap(const int* arr, size_t n, const operation& oper);

void __check_arr_equal(const int* arr1, const int* arr2, size_t n, const operation& oper);
