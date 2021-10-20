#pragma once
#include "operation.hpp"

#ifndef NDEBUG
	#define check_num_in_range(A, MIN, MAX)				__check_num_in_range(A, MIN, MAX)
	#define check_num_in_range_right_open(A, MIN, MAX)	__check_num_in_range_right_open(A, MIN, MAX)
	#define check_num_greater_than_zero(A)				__check_num_greater_than_zero(A)
	#define check_num_greater_than_other(A, B)			__check_num_greater_than_other(A, B)
	#define check_nums_are_equal(A, B)					__check_nums_are_equal(A, B)
	#define check_arr_sorted(ARR, N, OPER)				__check_arr_sorted(ARR, N, OPER)
	#define check_arr_partitioned(ARR, N, PIVOT, OPER)	__check_arr_partitioned(ARR, N, PIVOT, OPER)
	#define check_arr_is_binary_max_heap(ARR, N, OPER)	__check_arr_is_binary_max_heap(ARR, N, OPER)
	#define check_arr_equal(ARR1, ARR2, N, OPER)		__check_arr_equal(ARR1, ARR2, N, OPER)
#else
	#define check_num_in_range(A, MIN, MAX)
	#define check_num_in_range_right_open(A, MIN, MAX)
	#define check_greater_than_zero(A)
	#define check_num_greater_than_other(A, B)
	#define check_nums_are_equal(A, B)
	#define check_arr_sorted(ARR, N, OPER)
	#define check_arr_partitioned(ARR, N, PIVOT, OPER)
	#define check_arr_is_binary_max_heap(ARR, N, OPER)
	#define check_arr_equal(ARR1, ARR2, N, OPER)
#endif

void __check_num_in_range(int a, int min, int max);

void __check_num_in_range_right_open(size_t a, size_t min, size_t max);

void __check_num_greater_than_zero(int n);

void __check_num_greater_than_other(int a, int b);

void __check_nums_are_equal(size_t a, size_t b);

void __check_arr_sorted(const int* arr, size_t n, const operation& oper);

void __check_arr_partitioned(const int* arr, size_t n, size_t pivot, const operation& oper);

void __check_arr_is_binary_max_heap(const int* arr, size_t n, const operation& oper);

void __check_arr_equal(const int* arr1, const int* arr2, size_t n, const operation& oper);
