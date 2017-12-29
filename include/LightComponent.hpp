/*
Copyright (c) 2017 InversePalindrome
Rampancy - LightComponent.hpp
InversePalindrome.com
*/


#pragma once

#include "Component.hpp"

#include <OGRE/OgreLight.h>


class LightComponent : public Component
{
public:
	LightComponent(Ogre::Light* light);

	Ogre::Light* getLight();
	Ogre::Light* getLight() const;

private:
	Ogre::Light* light;
};

std::ostream& operator<<(std::ostream& os, const LightComponent& component);