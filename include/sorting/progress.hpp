#pragma once
#include "colors.hpp"
#include "numeric_utils.hpp"
#include <iostream>
#include <fmt/format.h>

#define PROGRESS

#ifdef PROGRESS
	#define PROGRESS_TITLE(STR)		__progress_title(STR)
	#define PROGRESS_INIT(STR, N)	__progress_init(STR, N)
	#define PROGRESS_STEP(I,N)		__progress_step(I, N)
	#define PROGRESS_END()			__progress_end()
#else
	#define PROGRESS_TITLE(STR)
	#define PROGRESS_INIT(STR, N)
	#define PROGRESS_END()
	#define PROGRESS_STEP()
#endif

inline void __progress_title(const char* const str)
{
	std::cout << BLUE << str << WHITE << std::endl;
}

inline void __progress_init(const char* const str, const size_t n)
{
	std::cout << fmt::format("{:28}  {:6} ", str, n);
}

inline void __progress_step(const size_t i, const size_t n)
{
	const size_t n_safe = max(n, 10);
	if (i % (n_safe/10) == 0)
		std::cout << BLUE << "." << WHITE;
}

inline void __progress_end()
{
	std::cout << std::endl;
}
