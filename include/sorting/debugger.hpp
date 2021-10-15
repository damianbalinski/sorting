#pragma once
#include <string>

#ifndef NDEBUG
	#define DBG_ARR_INIT(ARR, N)		__dbg_arr_init(ARR, N)
	#define DBG_ARR_STEP(ARR, N)		__dbg_arr_step(ARR, N)
	#define DBG_ARR_PRINT_STEP(ARR, N)	__dbg_arr_print_step(ARR, N)
#else
	#define DBG_ARR_INIT(ARR, N)
	#define DBG_ARR_STEP(ARR, N)
	#define DBG_ARR_PRINT_STEP
#endif


void __dbg_arr_init(const int* arr, size_t n);

void __dbg_arr_print_step(const int* arr, size_t n);

std::string __dbg_arr_step(const int* arr, size_t n);
