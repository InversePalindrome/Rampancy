/*
Copyright (c) 2017 InversePalindrome
Rampancy - Events.hpp
InversePalindrome.com
*/


#pragma once

#include "Direction.hpp"

#include <entityx/Entity.h>


struct ChangeDirection
{
	entityx::Entity entity;
	Direction direction;
};