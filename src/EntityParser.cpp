/*
Copyright (c) 2017 InversePalindrome
Rampancy - EntityParser.cpp
InversePalindrome.com
*/


#include "EntityParser.hpp"
#include "MeshComponent.hpp"
#include "LightComponent.hpp"
#include "PhysicsComponent.hpp"
#include "FilePaths.hpp"

#include <RapidXML/rapidxml.hpp>

#include <fstream>
#include <sstream>


EntityParser::EntityParser(entityx::EntityManager& entityManager) :
	entityManager(entityManager),
	sceneManager(nullptr)
{
}

entityx::Entity EntityParser::parseEntity(const std::string& fileName)
{
	auto entity = this->entityManager.create();

	rapidxml::xml_document<> doc;
	std::ifstream inFile(FP::entities + fileName);
	std::ostringstream buffer;
	
	buffer << inFile.rdbuf();
	inFile.close();

	std::string content(buffer.str());
	doc.parse<0>(&content[0]);

	auto* rootNode = doc.first_node("Entity");
	
	if (rootNode)
	{
		auto* node = rootNode->first_node("Physics");

		if (node)
		{
			std::size_t shape = 0u;
			float mass = 0.f;

			std::stringstream stream;
			stream << node->first_attribute("shape")->value() << ' ' << node->first_attribute("mass")->value();
			stream >> shape >> mass;

			entity.assign<PhysicsComponent>(static_cast<Shape>(shape), mass);
		}

		node = rootNode->first_node("Mesh");

		if (node)
		{
			const std::string& name = node->first_attribute("name")->value();

			auto* entityMesh = this->sceneManager->createEntity(name + ".mesh");
			auto* sceneNode = this->sceneManager->getRootSceneNode()->createChildSceneNode(name);

			entity.assign<MeshComponent>(entityMesh, sceneNode);
		}

		node = rootNode->first_node("Light");

		if (node)
		{
			const std::string& name = node->first_attribute("name")->value();

			std::size_t type;
			std::stringstream stream;

			stream << node->first_attribute("type")->value();
			stream >> type;

			auto* light = this->sceneManager->createLight(name);
			light->setType(static_cast<Ogre::Light::LightTypes>(type));

			auto* sceneNode = this->sceneManager->getRootSceneNode()->createChildSceneNode(name);

			entity.assign<LightComponent>(light, sceneNode);
		}
	}

	return entity;
}

void EntityParser::parseEntities(const std::string& fileName)
{
	rapidxml::xml_document<> doc;
	std::ifstream inFile(FP::entities + fileName);
	std::ostringstream buffer;

	buffer << inFile.rdbuf();
	inFile.close();

	std::string content(buffer.str());
	doc.parse<0>(&content[0]);

	auto* rootNode = doc.first_node("Entities");

	if (rootNode)
	{
		for (auto* node = rootNode->first_node("Entity"); node; node = node->next_sibling())
		{
			auto entity = this->parseEntity(node->first_attribute("filename")->value());

			float x = 0.f, y = 0.f, z = 0.f;

			std::stringstream stream;
			stream << node->first_attribute("x")->value() << ' ' << node->first_attribute("y")->value() << ' ' << node->first_attribute("z")->value();
			stream >> x >> y >> z;

			auto mesh = entity.component<MeshComponent>();

			if (mesh)
			{
				mesh->getSceneNode()->setPosition({ x, y, z });
			}

			auto light = entity.component<LightComponent>();

			if (light)
			{
				light->getSceneNode()->setPosition({ x, y, z });
			}
		}
	}
}

void EntityParser::setSceneManager(Ogre::SceneManager* sceneManager)
{
	this->sceneManager = sceneManager;
}