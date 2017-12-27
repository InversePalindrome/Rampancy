/*
Copyright (c) 2017 InversePalindrome
Rampancy - SceneComponent.hpp
InversePalindrome.com
*/


#pragma once

#include <OGRE/OgreSceneNode.h>


class SceneComponent
{
public:
	SceneComponent();
	SceneComponent(Ogre::SceneNode* sceneNode);

	Ogre::SceneNode* getSceneNode();
	void setSceneNode(Ogre::SceneNode* sceneNode);

private:
	Ogre::SceneNode* sceneNode;
};