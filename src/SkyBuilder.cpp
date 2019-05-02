/*
Copyright (c) 2018 InversePalindrome
Rampancy - SkyBuilder.cpp
InversePalindrome.com
*/


#include "SkyBuilder.hpp"
#include "Vector.hpp"
#include "EnumUtility.hpp"
#include "FilePaths.hpp"
#include "XMLAttribute.hpp"

#include <OGRE/OgrePlane.h>

#include <RapidXML/rapidxml.hpp>


void SkyBuilder::loadSky(const std::string& fileName)
{
    if (!this->sceneManager)
    {
        return;
    }

    rapidxml::xml_document<> doc;
    std::ifstream inFile(FP::skies + fileName);
    std::ostringstream buffer;

    buffer << inFile.rdbuf();
    inFile.close();

    std::string content(buffer.str());
    doc.parse<0>(&content[0]);

    const auto * rootNode = doc.first_node("Sky");

    if (rootNode)
    {
        const auto* node = rootNode->first_node("Box");

        if (node)
        {
            std::stringstream stream;

            std::string materialName;
            float distance = 0.f;

            stream << node->first_attribute("material")->value() << ' ' << node->first_attribute("distance")->value();
            stream >> materialName >> distance;

            this->sceneManager->setSkyBox(true, materialName, distance);
        }

        node = rootNode->first_node("Dome");

        if (node)
        {
            std::stringstream stream;

            std::string materialName;
            float curvature = 0.f, tiling = 0.f, distance = 0.f;

            stream << node->first_attribute("material")->value() << ' ' << node->first_attribute("curvature")->value() << ' '
                << node->first_attribute("tiling")->value() << ' ' << node->first_attribute("distance")->value();
            stream >> materialName >> curvature >> tiling >> distance;

            this->sceneManager->setSkyDome(true, materialName, curvature, tiling, distance);
        }

        node = rootNode->first_node("Plane");

        if (node)
        {
            std::stringstream stream;

            Ogre::Plane plane;

            std::string materialName;
            float scale = 0.f, tiling = 0.f, distance = 0.f;
            Vector normal;

            stream << node->first_attribute("material")->value() << ' ' << node->first_attribute("scale")->value() << ' '
                << node->first_attribute("tiling")->value() << ' ' << node->first_attribute("distance")->value() << ' ' <<
                node->first_attribute("normal")->value();
            stream >> materialName >> scale >> tiling >> distance >> normal;

            plane.d = distance;
            plane.normal = Utility::getVector(normal);

            this->sceneManager->setSkyPlane(true, plane, materialName, scale, tiling);
        }
    }
}

void SkyBuilder::setSceneManager(Ogre::SceneManager* sceneManager)
{
    this->sceneManager = sceneManager;
}