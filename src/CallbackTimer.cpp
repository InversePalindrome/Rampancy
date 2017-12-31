/*
Copyright (c) 2017 InversePalindrome
Rampancy - CallbackTimer.cpp
InversePalindrome.com
*/


#include "CallbackTimer.hpp"


CallbackTimer::CallbackTimer() :
	timer(io, boost::posix_time::milliseconds(0))
{
}

CallbackTimer::~CallbackTimer()
{
	if (thread.joinable())
	{
		thread.join();
	}
}