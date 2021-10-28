#pragma once
#include <chrono>
#include <functional>

class timer
{
public:
	timer(const std::function<void()> task): task(task) {}

	size_t run() const
	{
		using namespace std::chrono;

		const auto begin = steady_clock::now();
		task();
		const auto end = steady_clock::now();
		return duration_cast<microseconds>(end - begin).count();
	}

private:
	const std::function<void()> task;
};
