#pragma once

#ifndef NDEBUG
	#define check_num_in_range(A, MIN, MAX)					__check_num_in_range(A, MIN, MAX)
	#define check_num_in_range_right_open(A, MIN, MAX)		__check_num_in_range_right_open(A, MIN, MAX)
	#define check_num_greater_than_zero(A)					__check_num_greater_than_zero(A)
	#define check_num_greater_than(A, B)					__check_num_greater_than(A, B)
	#define check_num_greater_than_or_equal_to(A, B)		__check_num_greater_than_or_equal_to(A, B)
	#define check_num_equal(A, B)							__check_num_equal(A, B)
	#define check_num_add_overflow(A, B)					__check_num_add_overflow(A, B)
#else
	#define check_num_in_range(A, MIN, MAX)
	#define check_num_in_range_right_open(A, MIN, MAX)
	#define check_num_greater_than_zero(A)
	#define check_num_greater_than(A, B)
	#define check_num_greater_than_or_equal_to(A, B)
	#define check_num_equal(A, B)
	#define check_num_add_overflow(A, B)
#endif

void __check_num_in_range(int a, int min, int max);

void __check_num_in_range_right_open(size_t a, size_t min, size_t max);

void __check_num_greater_than_zero(long long n);

void __check_num_greater_than(int a, int b);

void __check_num_greater_than_or_equal_to(size_t a, size_t b);

void __check_num_equal(size_t a, size_t b);

void __check_num_add_overflow(size_t a, size_t b);
