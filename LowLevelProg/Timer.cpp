#include "Timer.hpp"
#include <iostream>

Timer::Timer()
{
	m_startPoint = MyClock::now();
}

Timer::~Timer()
{
	Stop();
}

void Timer::Stop()
{
	MyTimePoint endTimePoint = MyClock::now();

	long long start = std::chrono::time_point_cast<std::chrono::nanoseconds>(m_startPoint).time_since_epoch().count();
	long long end = std::chrono::time_point_cast<std::chrono::nanoseconds>(endTimePoint).time_since_epoch().count();

	long long duration = end - start;
	double us = duration * 0.001;

	std::cout << duration << "ns (" << us << "us)" << std::endl;
}