/*
Copyright (c) 2017 InversePalindrome
Rampancy - LightComponent.hpp
InversePalindrome.com
*/


#pragma once

#include <OGRE/OgreLight.h>
#include <OGRE/OgreSceneNode.h>


class LightComponent
{
public:
	LightComponent(Ogre::Light* light, Ogre::SceneNode* sceneNode);

	Ogre::Light* getLight();
	Ogre::SceneNode* getSceneNode();

private:
	Ogre::Light* light;
	Ogre::SceneNode* sceneNode;
};