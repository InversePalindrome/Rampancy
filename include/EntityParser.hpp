/*
Copyright (c) 2017 InversePalindrome
Rampancy - EntityParser.hpp
InversePalindrome.com
*/


#pragma once

#include "XMLAttribute.hpp"

#include <OGRE/OgreSceneManager.h>

#include <entityx/entityx.h>

#include <RapidXML/rapidxml.hpp>

#include <string>
#include <functional>
#include <unordered_map>


enum class ParsingMode { Group, Individual };

class EntityParser
{
public:
    EntityParser(entityx::EntityManager& entityManager, entityx::EventManager& eventManager);

    void parseEntity(entityx::Entity& entity, const std::string& fileName);
    void parseEntity(entityx::Entity& entity, const rapidxml::xml_node<char>* entityNode);

    void parseEntities(ParsingMode mode, const std::string& fileName);

    void setSceneManager(Ogre::SceneManager* sceneManager);
    void setCamera(Ogre::Camera* camera);

private:
    entityx::EntityManager& entityManager;
    entityx::EventManager& eventManager;
    Ogre::SceneManager* sceneManager;
    Ogre::Camera* camera;

    std::unordered_map<std::string, std::function<void(entityx::Entity&, const XMLAttribute& attribute)>> parsers;
};