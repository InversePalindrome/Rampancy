/*
Copyright (c) 2017 InversePalindrome
Rampancy - MeshComponent.hpp
InversePalindrome.com
*/


#pragma once

#include <OGRE/OgreEntity.h>
#include <OGRE/OgreSceneNode.h>


class MeshComponent
{
public:
	MeshComponent(Ogre::Entity* entity, Ogre::SceneNode* sceneNode);

	Ogre::Entity* getEntity();
	Ogre::SceneNode* getSceneNode();

private:
	Ogre::Entity* entity;
	Ogre::SceneNode* sceneNode;
};