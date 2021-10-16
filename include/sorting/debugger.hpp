#pragma once
#include <string>

#ifndef NDEBUG
	#define DBG_ARR_INIT(ARR, N)			__dbg_arr_init(ARR, N)
	#define DBG_ARR_STEP(ARR, N)			__dbg_arr_step(ARR, N)
	#define DBG_ARR_PIVOT(ARR, N, P)		__dbg_arr_pivot(ARR, N, P)
	#define DBG_ARR_PRINT_STEP(ARR, N)		__dbg_arr_print_step(ARR, N)
	#define DBG_ARR_PRINT_PIVOT(ARR, N, P)	__dbg_arr_print_pivot(ARR, N, P)
#else
	#define DBG_ARR_INIT(ARR, N)
	#define DBG_ARR_STEP(ARR, N)
	#define DBG_ARR_PIVOT(ARR, N, P)
	#define DBG_ARR_PRINT_STEP(ARR, N)
	#define DBG_ARR_PRINT_PIVOT(ARR, N, P)
#endif


void __dbg_arr_init(const int* arr, size_t n);

void __dbg_arr_print_step(const int* arr, size_t n);

void __dbg_arr_print_pivot(const int* arr, size_t n, size_t pivot);

std::string __dbg_arr_step(const int* arr, size_t n);

std::string __dbg_arr_pivot(const int* arr, size_t n, size_t pivot);
