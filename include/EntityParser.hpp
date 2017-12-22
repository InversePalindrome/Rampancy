/*
Copyright (c) 2017 InversePalindrome
Rampancy - EntityParser.hpp
InversePalindrome.com
*/


#pragma once

#include <string>

#include <entityx/entityx.h>

#include <OGRE/OgreSceneManager.h>


class EntityParser
{
public:
	EntityParser(entityx::EntityManager& entityManager);

	void parseEntity(const std::string& fileName);

	void setSceneManager(Ogre::SceneManager* sceneManager);

private:
	entityx::EntityManager& entityManager;
	Ogre::SceneManager* sceneManager;
};