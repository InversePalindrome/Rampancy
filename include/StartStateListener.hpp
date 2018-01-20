/*
Copyright (c) 2017 InversePalindrome
Rampancy - StartStateListener.hpp
InversePalindrome.com
*/


#pragma once

#include "Events.hpp"


struct StartStateListener
{
	StartStateListener();

	void receive(const KeyPressed& event);

	bool isKeyPressed;
};