#pragma once
#include "colors.hpp"
#include "numeric_utils.hpp"
#include <string>
#include <iostream>

#define PROGRESS

#ifdef PROGRESS
	#define PROGRESS_INIT(STR)	__progress_init(STR)
	#define PROGRESS_STEP(I,N)	__progress_step(I, N)
	#define PROGRESS_END()		__progress_end()
#else
	#define PROGRESS_INIT(STR)
	#define PROGRESS_END()
	#define PROGRESS_STEP()
#endif

inline void __progress_init(std::string str)
{
	std::cout << str;
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
