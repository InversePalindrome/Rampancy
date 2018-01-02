/*
Copyright (c) 2017 InversePalindrome
Rampancy - Events.hpp
InversePalindrome.com
*/


#pragma once

#include "Direction.hpp"

#include "OGRE/OgreSceneNode.h"

#include <btQuaternion.h>

#include <entityx/Entity.h>


struct EntityParsed
{
	entityx::Entity entity;
};

struct CreatePhysicalBody
{
	entityx::Entity entity;
};

struct ChangeDirection
{
	entityx::Entity entity;
	Direction direction;
};

struct ChangeRotation
{
	entityx::Entity entity;
	float yaw, pitch, roll;
};