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

	entityx::Entity parseEntity(const std::string& fileName);
	void parseEntities(const std::string& fileNames);

	void setSceneManager(Ogre::SceneManager* sceneManager);
	void setCamera(Ogre::Camera* camera);

private:
	entityx::EntityManager& entityManager;
	Ogre::SceneManager* sceneManager;
	Ogre::Camera* camera;
};