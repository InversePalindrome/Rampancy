/*
Copyright (c) 2017 InversePalindrome
Rampancy - LightComponent.cpp
InversePalindrome.com
*/


#include "LightComponent.hpp"


LightComponent::LightComponent(Ogre::Light* light) :
    Component("Light"),
    light(light)
{
}

Ogre::Light* LightComponent::getLight()
{
    return this->light;
}

Ogre::Light* LightComponent::getLight() const
{
    return this->light;
}

std::ostream& operator<<(std::ostream& os, const LightComponent& component)
{
    os << "type " << component.getLight()->getType();

    return os;
}