/*
Copyright (c) 2018 InversePalindrome
Rampancy - TerrainBuilder.hpp
InversePalindrome.com
*/


#pragma once

#include <OGRE/OgreSceneManager.h>
#include <OGRE/Terrain/OgreTerrainGroup.h>

#include <string>


class TerrainBuilder
{
public:
    ~TerrainBuilder();

    void loadTerrain(const std::string& fileName);

    void setSceneManager(Ogre::SceneManager* sceneManager);

private:
    Ogre::SceneManager* sceneManager;
    Ogre::TerrainGroup* terrainGroup;
    Ogre::TerrainGlobalOptions* terrainOptions;
};