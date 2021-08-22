#pragma once
#include "comparator.hpp"

#ifndef NDEBUG
	#define check_num_in_range(A, MIN, MAX)				__check_num_in_range(A, MIN, MAX)
	#define check_num_greater_than_zero(A)				__check_num_greater_than_zero(A)
	#define check_num_greater_than_other(A, B)			__check_num_greater_than_other(A, B)
	#define check_arr_sorted(ARR, N, COMP)				__check_arr_sorted(ARR, N, COMP)
	#define check_arr_partitioned(ARR, N, PIVOT, COMP)	__check_arr_partitioned(ARR, N, PIVOT, COMP)
	#define check_arr_equal(ARR1, ARR2, N, COMP)		__check_arr_equal(ARR1, ARR2, N, COMP)
#else
	#define check_num_in_range(A, MIN, MAX)
	#define check_greater_than_zero(A)
	#define check_num_greater_than_other(A, B)
	#define check_arr_sorted(ARR, N, COMP)
	#define check_arr_partitioned(ARR, N, PIVOT, COMP)
	#define check_arr_equal(ARR1, ARR2, N, COMP)
#endif

void __check_num_in_range(int a, int min, int max);

void __check_num_greater_than_zero(int n);

void __check_num_greater_than_other(int a, int b);

void __check_arr_sorted(const int* arr, size_t n, const comparator& comp);

void __check_arr_partitioned(const int* arr, size_t n, size_t pivot, const comparator& comp);

void __check_arr_equal(const int* arr1, const int* arr2, size_t n, const comparator& comp);
