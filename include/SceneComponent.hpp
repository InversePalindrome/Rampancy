/*
Copyright (c) 2017 InversePalindrome
Rampancy - SceneComponent.hpp
InversePalindrome.com
*/


#pragma once

#include "Component.hpp"

#include <OGRE/OgreSceneNode.h>


class SceneComponent : public Component
{
public:
	SceneComponent();
	SceneComponent(Ogre::SceneNode* sceneNode);

	Ogre::SceneNode* getSceneNode();
	Ogre::Vector3 getPosition() const;
	Ogre::Quaternion getRotation() const;

	void setSceneNode(Ogre::SceneNode* sceneNode);

private:
	Ogre::SceneNode* sceneNode;
};