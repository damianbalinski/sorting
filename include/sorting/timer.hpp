#pragma once
#include <chrono>
#include <iostream>
#include <functional>

inline void timer(std::function<void()> task)
{
	auto begin = std::chrono::steady_clock::now();
	task();
	auto end = std::chrono::steady_clock::now();

	std::cout << "Total time = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[us]" << std::endl;
}
