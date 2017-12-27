/*
Copyright (c) 2017 InversePalindrome
Rampancy - LightComponent.cpp
InversePalindrome.com
*/


#include "LightComponent.hpp"


LightComponent::LightComponent(Ogre::Light* light) :
	light(light)
{
}

Ogre::Light* LightComponent::getLight()
{
	return this->light;
}