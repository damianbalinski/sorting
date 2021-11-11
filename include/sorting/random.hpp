#pragma once
#include <cstdlib>
#include <ctime>

inline int __random_seed()
{
	srand(time(nullptr));
	return 0;
}

inline void set_random_seed()
{
	static int __ignored = __random_seed();
}
