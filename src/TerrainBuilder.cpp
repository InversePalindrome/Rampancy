/*
Copyright (c) 2018 InversePalindrome
Rampancy - TerrainBuilder.cpp
InversePalindrome.com
*/


#include "TerrainBuilder.hpp"
#include "EnumUtility.hpp"
#include "FilePaths.hpp"

#include <RapidXML/rapidxml.hpp>

#include <fstream>
#include <sstream>


TerrainBuilder::~TerrainBuilder()
{
    delete terrainGroup;
    delete terrainOptions;
}

void TerrainBuilder::loadTerrain(const std::string& fileName)
{
    if (!this->sceneManager)
    {
        return;
    }

    rapidxml::xml_document<> doc;
    std::ifstream inFile(FP::terrains + fileName);
    std::ostringstream buffer;

    buffer << inFile.rdbuf();
    inFile.close();

    std::string content(buffer.str());
    doc.parse<0>(&content[0]);

    const auto * rootNode = doc.first_node("Terrain");

    if (rootNode)
    {
        if (this->terrainGroup)
        {
            delete this->terrainGroup;
        }
        if (this->terrainOptions)
        {
            delete this->terrainOptions;
        }

        const auto* node = rootNode->first_node("Size");

        std::size_t terrainSize = 0u;
        float worldSize = 0.f;

        if (node)
        {
            std::stringstream stream;
            stream << node->first_attribute("terrain")->value() << ' ' << node->first_attribute("world")->value();
            stream >> terrainSize >> worldSize;
        }

        node = rootNode->first_node("Alignment");

        Ogre::Terrain::Alignment alignmentType = Ogre::Terrain::ALIGN_X_Y;

        if (node)
        {
            std::stringstream stream;
            stream << node->first_attribute("type")->value();
            stream >> alignmentType;
        }

        this->terrainGroup = new Ogre::TerrainGroup(this->sceneManager, alignmentType, terrainSize, worldSize);
        this->terrainOptions = new Ogre::TerrainGlobalOptions();
    }
}

void TerrainBuilder::setSceneManager(Ogre::SceneManager* sceneManager)
{
    this->sceneManager = sceneManager;
}