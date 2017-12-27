/*
Copyright (c) 2017 InversePalindrome
Rampancy - MeshComponent.hpp
InversePalindrome.com
*/


#pragma once

#include <OGRE/OgreEntity.h>


class MeshComponent
{
public:
	MeshComponent();
	MeshComponent(Ogre::Entity* entity);

	Ogre::Entity* getEntity();
	void setEntity(Ogre::Entity* entity);

private:
	Ogre::Entity* entity;
};