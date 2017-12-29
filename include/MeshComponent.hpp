/*
Copyright (c) 2017 InversePalindrome
Rampancy - MeshComponent.hpp
InversePalindrome.com
*/


#pragma once

#include "Component.hpp"

#include <OGRE/OgreEntity.h>


class MeshComponent : public Component
{
	friend std::ostream& operator<<(std::ostream& os, const MeshComponent& component);

public:
	MeshComponent();
	MeshComponent(Ogre::Entity* entity);

	Ogre::Entity* getEntity();
	Ogre::Entity* getEntity() const;

	void setEntity(Ogre::Entity* entity);

private:
	Ogre::Entity* entity;
};

std::ostream& operator<<(std::ostream& os, const MeshComponent& component);