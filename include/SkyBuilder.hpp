/*
Copyright (c) 2018 InversePalindrome
Rampancy - SkyBuilder.hpp
InversePalindrome.com
*/


#pragma once

#include <OGRE\OgreSceneManager.h>

#include <string>


class SkyBuilder
{
public:
	void loadSky(const std::string& fileName);
	
	void setSceneManager(Ogre::SceneManager* sceneManager);

private:
	Ogre::SceneManager* sceneManager;
};