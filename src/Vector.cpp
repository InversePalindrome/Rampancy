/*
Copyright (c) 2018 InversePalindrome
Rampancy - Vector.cpp
InversePalindrome.com
*/


#include "Vector.hpp"


Ogre::Vector3 Utility::getVector(Vector vector)
{
	switch (vector)
	{
	case Vector::Zero:
		return Ogre::Vector3::ZERO;
	case Vector::X:
		return Ogre::Vector3::UNIT_X;
	case Vector::Y:
		return Ogre::Vector3::UNIT_Y;
	case Vector::Z:
		return Ogre::Vector3::UNIT_Z;
	case Vector::NegativeX:
		return Ogre::Vector3::NEGATIVE_UNIT_X;
	case Vector::NegativeY:
		return Ogre::Vector3::NEGATIVE_UNIT_Y;
	case Vector::NegativeZ:
		return Ogre::Vector3::NEGATIVE_UNIT_Z;
	default:
		return Ogre::Vector3::ZERO;
	}
}