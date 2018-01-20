/*
Copyright (c) 2018 InversePalindrome
Rampancy - Vector.hpp
InversePalindrome.com
*/


#pragma once

#include <OGRE/OgreVector3.h>


enum class Vector { Zero, X, Y, Z, NegativeX, NegativeY, NegativeZ };


namespace Utility
{
	Ogre::Vector3 getVector(Vector vector);
}