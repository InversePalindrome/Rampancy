/*
Copyright (c) 2017 InversePalindrome
Rampancy - StartStateListener.cpp
InversePalindrome.com
*/


#include "StartStateListener.hpp"


StartStateListener::StartStateListener() :
	isKeyPressed(false)
{
}

void StartStateListener::receive(const KeyPressed& event)
{
	this->isKeyPressed = true;
}