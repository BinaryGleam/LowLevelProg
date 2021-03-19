#pragma once
#include <chrono>

typedef std::chrono::high_resolution_clock MyClock;
typedef std::chrono::time_point<std::chrono::high_resolution_clock> MyTimePoint;
//typedef std::chrono::time_point_cast<std::chrono::microseconds> MyDuration;

class Timer
{
	MyTimePoint m_startPoint;

public:
	Timer();
	~Timer();

	void Stop();
};