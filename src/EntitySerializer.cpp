/*
Copyright (c) 2017 InversePalindrome
Rampancy - EntitySerializer.cpp
InversePalindrome.com
*/


#include "EntitySerializer.hpp"
#include "Components.hpp"
#include "FilePaths.hpp"

#include <brigand/algorithms/for_each.hpp>

#include <RapidXML/rapidxml_print.hpp>


EntitySerializer::EntitySerializer(entityx::EntityManager& entityManager) :
	entityManager(entityManager)
{
}

void EntitySerializer::serialize(const std::string& fileName)
{
	this->saveEntities();

	rapidxml::xml_document<> doc;

	auto* decl = doc.allocate_node(rapidxml::node_declaration);
	decl->append_attribute(doc.allocate_attribute("version", "1.0"));
	decl->append_attribute(doc.allocate_attribute("encoding", "UTF-8"));
	doc.append_node(decl);

	auto* entitiesNode = doc.allocate_node(rapidxml::node_element, "Entities");

	for (tree<std::string>::sibling_iterator i = std::begin(this->entities); i != std::end(this->entities); ++i)
	{
		auto* entityNode = doc.allocate_node(rapidxml::node_element, "Entity");

		for (tree<std::string>::sibling_iterator j = std::begin(i); j != std::end(i); ++j)
		{
			rapidxml::xml_node<char>* dataNode = nullptr;

			std::string data, key, value;

			if (j == std::begin(i))
			{
				data = j->c_str();
			}
			else
			{
				dataNode = doc.allocate_node(rapidxml::node_element, j->c_str());
				data = *std::cbegin(j);
			}

			std::istringstream iStream(data);

			while (iStream >> key >> value)
			{
				if (j == std::begin(i))
				{
					entityNode->append_attribute(doc.allocate_attribute(doc.allocate_string(key.c_str()), doc.allocate_string(value.c_str())));
				}
				else
				{
					dataNode->append_attribute(doc.allocate_attribute(doc.allocate_string(key.c_str()), doc.allocate_string(value.c_str())));
				}
			}
			
			if (dataNode)
			{
				entityNode->append_node(dataNode);
			}
		}

		entitiesNode->append_node(entityNode);
	}

	doc.append_node(entitiesNode);

	std::ofstream outFile(FP::savedGames + fileName);

	outFile << doc;
}

void EntitySerializer::saveEntities()
{
	brigand::for_each<Components>([this](auto componentType)
	{
		using Type = decltype(componentType)::type;
		entityx::ComponentHandle<Type> component;

		for (auto entity : this->entityManager.entities_with_components(component))
		{
			auto entityItr = std::find(std::begin(this->entities), std::end(this->entities), std::to_string(entity.id().id()));

			bool isNewEntity = entityItr == std::end(this->entities);

			if (isNewEntity)
			{
				entityItr = this->entities.insert(entityItr, std::to_string(entity.id().id()));

				std::string entityTransform;

				auto physics = entity.component<PhysicsComponent>();
				auto scene = entity.component<SceneComponent>();

				if (physics)
				{
					const auto& position = physics->getPosition();
					const auto& rotation = physics->getRotation();

					entityTransform = "xPos " + std::to_string(position.x()) + " yPos " + std::to_string(position.y()) + " zPos " + std::to_string(position.z())
						+ " wRot " + std::to_string(rotation.w()) + " xRot " + std::to_string(rotation.x()) + " yRot " + std::to_string(rotation.y()) + " zRot " +
						std::to_string(rotation.z());
				}
				else if (scene)
				{
					const auto& position = scene->getPosition();
					const auto& rotation = scene->getRotation();

					entityTransform = "xPos " + std::to_string(position.x) + " yPos " + std::to_string(position.y) + " zPos " + std::to_string(position.z)
						+ " wRot " + std::to_string(rotation.w) + " xRot " + std::to_string(rotation.x) + " yRot " + std::to_string(rotation.y) + " zRot " +
						std::to_string(rotation.z);
				}

				this->entities.append_child(entityItr, entityTransform);
			}

			std::stringstream stream;

			stream << *component.get();
			std::string componentData(std::istreambuf_iterator<char>(stream), {});

			entityItr = this->entities.append_child(entityItr, component->getName());
			this->entities.append_child(entityItr, componentData);
		}
	});
}