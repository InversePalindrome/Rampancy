/*
Copyright (c) 2017 InversePalindrome
Rampancy - LightComponent.cpp
InversePalindrome.com
*/


#include "LightComponent.hpp"


LightComponent::LightComponent(Ogre::Light* light, Ogre::SceneNode* sceneNode) :
	light(light),
	sceneNode(sceneNode)
{
	sceneNode->attachObject(light);
}

Ogre::Light* LightComponent::getLight()
{
	return this->light;
}

Ogre::SceneNode* LightComponent::getSceneNode()
{
	return this->sceneNode;
}