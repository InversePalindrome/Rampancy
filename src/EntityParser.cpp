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
#include "Events.hpp"
#include "Tags.hpp"
#include "FilePaths.hpp"
#include "EnumUtility.hpp"

#include <fstream>
#include <sstream>


EntityParser::EntityParser(entityx::EntityManager& entityManager, entityx::EventManager& eventManager) :
	entityManager(entityManager),
	eventManager(eventManager),
	sceneManager(nullptr),
	camera(nullptr)
{
	parsers["Physics"] = [](auto& entity, const auto* node)
	{
		Shape shape;
		float mass = 0.f, impulse = 0.f, damping = 0.f;

		std::stringstream stream;
		stream << node->first_attribute("shape")->value() << ' ' << node->first_attribute("mass")->value() <<
			' ' << node->first_attribute("impulse")->value() << ' ' << node->first_attribute("damping")->value();
		stream >> shape >> mass >> impulse >> damping;

		entity.assign<PhysicsComponent>(shape, mass, impulse, damping);
	};
	parsers["Scene"] = [](auto& entity, const auto* node)
	{
		entity.assign<SceneComponent>();
	};
	parsers["Mesh"] = [this](auto& entity, const auto* node)
	{
		const std::string& name = node->first_attribute("name")->value();

		auto* entityMesh = sceneManager->createEntity(name);

		entity.assign<MeshComponent>(entityMesh);
	};
	parsers["Light"] = [this](auto& entity, const auto* node)
	{
		Ogre::Light::LightTypes type;
		std::stringstream stream;

		stream << node->first_attribute("type")->value();
		stream >> type;

		auto* light = sceneManager->createLight();
		light->setType(type);

		entity.assign<LightComponent>(light);
	};
	parsers["Object"] = [](auto& entity, const auto* node)
	{
		ObjectType type;
		std::stringstream stream;

		stream << node->first_attribute("type")->value();
		stream >> type;

		entity.assign<ObjectComponent>(type);
	};
	parsers["Camera"] = [this](auto& entity, const auto* node)
	{
		entity.assign<CameraComponent>(camera);
	};
	parsers["Player"] = [](auto& entity, const auto* node)
	{
		entity.assign<Player>();
	};
}

void EntityParser::parseEntity(entityx::Entity& entity, const std::string& fileName)
{
	rapidxml::xml_document<> doc;
	std::ifstream inFile(FP::entities + fileName);
	std::ostringstream buffer;
	
	buffer << inFile.rdbuf();
	inFile.close();

	std::string content(buffer.str());
	doc.parse<0>(&content[0]);

	const auto* rootNode = doc.first_node("Entity");
	
	if (rootNode)
	{
		this->parseEntity(entity, rootNode);
	}
}

void EntityParser::parseEntity(entityx::Entity& entity, const rapidxml::xml_node<char>* entityNode)
{
	for (const auto* node = entityNode->first_node(); node; node = node->next_sibling())
	{
		if (this->parsers.count(node->name()))
		{
			this->parsers[node->name()](entity, node);
		}
	}
}

void EntityParser::parseEntities(ParsingMode mode, const std::string& fileName)
{
	std::string entitiesPath;

	if (mode == ParsingMode::Individual)
	{
		entitiesPath = FP::entities + fileName;
	}
	else
	{
		entitiesPath = FP::savedGames + fileName;
	}

	rapidxml::xml_document<> doc;
	std::ifstream inFile(entitiesPath);
	std::ostringstream buffer;

	buffer << inFile.rdbuf();
	inFile.close();

	std::string content(buffer.str());
	doc.parse<0>(&content[0]);

	const auto* rootNode = doc.first_node("Entities");

	if (rootNode)
	{
		for (const auto* node = rootNode->first_node("Entity"); node; node = node->next_sibling())
		{
			auto entity = this->entityManager.create();

			if (mode == ParsingMode::Group)
			{
				this->parseEntity(entity, node);
			}
			else if (mode == ParsingMode::Individual)
			{
				this->parseEntity(entity, node->first_attribute("filename")->value());
			}
		
			this->eventManager.emit(EntityParsed{ entity });

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