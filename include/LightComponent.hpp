/*
Copyright (c) 2017 InversePalindrome
Rampancy - LightComponent.hpp
InversePalindrome.com
*/


#pragma once

#include <OGRE/OgreLight.h>


class LightComponent
{
public:
	LightComponent(Ogre::Light* light);

	Ogre::Light* getLight();

private:
	Ogre::Light* light;
};