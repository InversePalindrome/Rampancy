/*
Copyright (c) 2017 InversePalindrome
Rampancy - Game.cpp
InversePalindrome.com
*/


#include "Game.hpp"


Game::Game(const std::string& name) :
	name(name)
{
}

std::string Game::getName() const
{
	return this->name;
}