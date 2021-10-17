#pragma once
#include "colors.hpp"
#include <string>

#define PROGRESS

#ifdef PROGRESS
	#define PROGRESS_INIT(STR)	__progress_init(STR)
	#define PROGRESS_STEP()		__progress_step()
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

inline void __progress_step()
{
	std::cout << BLUE << "." << WHITE;
}

inline void __progress_end()
{
	std::cout << std::endl;
}
