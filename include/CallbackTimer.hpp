/*
Copyright (c) 2017 InversePalindrome
Rampancy - CallbackTimer.hpp
InversePalindrome.com
*/


#pragma once

#include <boost/asio/io_service.hpp>
#include <boost/asio/deadline_timer.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

#include <thread>


class CallbackTimer
{
public:
	CallbackTimer();
	~CallbackTimer();

	template<typename T>
	void addCallback(T&& function, std::size_t timeInMilliseconds);

private:
	boost::asio::io_service io;
	boost::asio::deadline_timer timer;
	std::thread thread;
};

template<typename T>
void CallbackTimer::addCallback(T&& function, std::size_t timeInMilliseconds)
{
	this->timer.expires_from_now(boost::posix_time::milliseconds(timeInMilliseconds));

	this->timer.async_wait(std::forward<T>(function));

	this->thread = std::thread([this]() { this->io.run(); });
}