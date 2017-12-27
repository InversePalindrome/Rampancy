/*
Copyright (c) 2017 InversePalindrome
Rampancy - Events.hpp
InversePalindrome.com
*/


#pragma once

#include "Direction.hpp"

#include "OGRE/OgreSceneNode.h"

#include <entityx/Entity.h>


struct CreatePhysicalBody
{
	entityx::Entity entity;
};

struct ChangeDirection
{
	entityx::Entity entity;
	Direction direction;
};