/*
Copyright (c) 2017 InversePalindrome
Rampancy - MeshComponent.hpp
InversePalindrome.com
*/


#pragma once

#include "Component.hpp"

#include <OGRE/OgreEntity.h>
#include <Ogre/OgreSceneManager.h>


class MeshComponent : public Component
{
	friend std::ostream& operator<<(std::ostream& os, const MeshComponent& component);

public:
	MeshComponent();
	explicit MeshComponent(Ogre::Entity* entity);
	MeshComponent(Ogre::Entity* entity, Ogre::SceneManager::PrefabType prefabType);

	Ogre::Entity* getEntity();
	Ogre::Entity* getEntity() const;

	Ogre::SceneManager::PrefabType getPrefabType() const;

	void setEntity(Ogre::Entity* entity);

private:
	Ogre::Entity* entity;
	Ogre::SceneManager::PrefabType prefabType;
};

std::ostream& operator<<(std::ostream& os, const MeshComponent& component);