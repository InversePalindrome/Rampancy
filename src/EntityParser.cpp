/*
Copyright (c) 2017 InversePalindrome
Rampancy - EntityParser.cpp
InversePalindrome.com
*/


#include "EntityParser.hpp"
#include "MeshComponent.hpp"
#include "PhysicsComponent.hpp"

#include <RapidXML/rapidxml.hpp>

#include <fstream>
#include <sstream>


EntityParser::EntityParser(entityx::EntityManager& entityManager) :
	entityManager(entityManager),
	sceneManager(nullptr)
{
}

void EntityParser::parseEntity(const std::string& fileName)
{
	auto entity = this->entityManager.create();
	
	rapidxml::xml_document<> doc;
	std::ifstream inFile(fileName);
	std::ostringstream buffer;
	
	buffer << inFile.rdbuf();
	inFile.close();

	std::string content(buffer.str());
	doc.parse<0>(&content[0]);

	auto* rootNode = doc.first_node("Entity");

	auto* node = rootNode->first_node("Physics");

	std::size_t shape = 0u;
	float mass = 0.f;

	std::stringstream stream;
	stream << node->first_attribute("shape")->value() << ' ' << node->first_attribute("mass")->value();
	stream >> shape >> mass;

	entity.assign<PhysicsComponent>(static_cast<Shape>(shape), mass);
	
	node = rootNode->first_node("Mesh");

	const std::string& meshName = node->first_attribute("name")->value();

	auto* entityMesh = this->sceneManager->createEntity(meshName + ".mesh");
	auto* sceneNode = this->sceneManager->getRootSceneNode()->createChildSceneNode(meshName);

	entity.assign<MeshComponent>(entityMesh, sceneNode);
}

void EntityParser::setSceneManager(Ogre::SceneManager* sceneManager)
{
	this->sceneManager = sceneManager;
}