/*
Copyright (c) 2017 InversePalindrome
Rampancy - EntityParser.cpp
InversePalindrome.com
*/


#include "EntityParser.hpp"
#include "MeshComponent.hpp"
#include "LightComponent.hpp"
#include "PhysicsComponent.hpp"
#include "ObjectComponent.hpp"
#include "CameraComponent.hpp"
#include "SceneComponent.hpp"
#include "Tags.hpp"
#include "FilePaths.hpp"

#include <RapidXML/rapidxml.hpp>

#include <fstream>
#include <sstream>


EntityParser::EntityParser(entityx::EntityManager& entityManager) :
	entityManager(entityManager),
	sceneManager(nullptr),
	camera(nullptr)
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
			float mass = 0.f, impulse = 0.f, damping = 0.f;

			std::stringstream stream;
			stream << node->first_attribute("shape")->value() << ' ' << node->first_attribute("mass")->value() <<
				' ' << node->first_attribute("impulse")->value() << ' ' << node->first_attribute("damping")->value();
			stream >> shape >> mass >> impulse >> damping;

			entity.assign<PhysicsComponent>(static_cast<Shape>(shape), mass, impulse, damping);
		}

		node = rootNode->first_node("Mesh");
		
		if (node)
		{
			const std::string& name = node->first_attribute("name")->value();

			auto* entityMesh = this->sceneManager->createEntity(name + ".mesh");

			entity.assign<MeshComponent>(entityMesh);
		}

		node = rootNode->first_node("Light");

		if (node)
		{
			std::size_t type = 0u;
			std::stringstream stream;

			stream << node->first_attribute("type")->value();
			stream >> type;

			auto* light = this->sceneManager->createLight();
			light->setType(static_cast<Ogre::Light::LightTypes>(type));

			entity.assign<LightComponent>(light);
		}

		node = rootNode->first_node("Object");

		if (node)
		{
			std::size_t objectType = 0u;
			std::stringstream stream;

			stream << node->first_attribute("type")->value();
			stream >> objectType;

			entity.assign<ObjectComponent>(static_cast<ObjectType>(objectType));
		}

		node = rootNode->first_node("Camera");

		if(node)
		{
			entity.assign<CameraComponent>(this->camera);
		}
			
		node = rootNode->first_node("Player");

		if (node)
		{
			entity.assign<Player>();
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
		
			float xPos = 0.f, yPos = 0.f, zPos = 0.f, wRot = 0.f, xRot = 0.f, yRot = 0.f, zRot = 0.f;

			std::stringstream stream;
			stream << node->first_attribute("xPos")->value() << ' ' << node->first_attribute("yPos")->value() << ' ' << node->first_attribute("zPos")->value()
				<< ' ' << node->first_attribute("wRot")->value() << ' ' << node->first_attribute("xRot")->value() << ' ' << node->first_attribute("yRot")->value()
				<< ' ' << node->first_attribute("zRot")->value();
			stream >> xPos >> yPos >> zPos >> wRot >> xRot >> yRot >> zRot;
			
			auto physics = entity.component<PhysicsComponent>();

			if (physics)
			{
				btTransform transform;
				transform.setIdentity();
				transform.setOrigin({ xPos, yPos, zPos });
				transform.setRotation({ xRot, yRot, zRot, wRot });
				physics->getBody()->setCenterOfMassTransform(transform);
			}

			auto scene = entity.component<SceneComponent>();

			if (scene)
			{
				scene->getSceneNode()->setPosition({ xPos, yPos, zPos });
				scene->getSceneNode()->rotate({ wRot, xRot, yRot, zRot });
			}
		}
	}
}

void EntityParser::setSceneManager(Ogre::SceneManager* sceneManager)
{
	this->sceneManager = sceneManager;
}

void EntityParser::setCamera(Ogre::Camera* camera)
{
	this->camera = camera;
}