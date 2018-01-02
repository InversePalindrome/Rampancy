/*
Copyright (c) 2017 InversePalindrome
Rampancy - GraphicsSystem.cpp
InversePalindrome.com
*/


#include "GraphicsSystem.hpp"
#include "MeshComponent.hpp"
#include "CameraComponent.hpp"
#include "LightComponent.hpp"
#include "Events.hpp"


void GraphicsSystem::configure(entityx::EventManager& eventManager)
{
	eventManager.subscribe<EntityParsed>(*this);

	this->eventManager = &eventManager;
}

void GraphicsSystem::update(entityx::EntityManager& entityManager, entityx::EventManager& eventManager, entityx::TimeDelta deltaTime)
{
	
}

void GraphicsSystem::receive(const EntityParsed& event)
{
	auto entity = event.entity;
	
	auto scene = entity.component<SceneComponent>();

	if (scene)
	{
		auto camera = entity.component<CameraComponent>();
		auto mesh = entity.component<MeshComponent>();
		auto light = entity.component<LightComponent>();

	    if (camera)
	    {
		    scene->setSceneNode(this->sceneManager->getRootSceneNode()->createChildSceneNode());
		    scene->getSceneNode()->attachObject(camera->getCamera());
			
		    this->eventManager->emit(CreatePhysicalBody{ entity });
	    }
		else if (mesh)
		{
			scene->setSceneNode(this->sceneManager->getRootSceneNode()->createChildSceneNode());
			scene->getSceneNode()->attachObject(mesh->getEntity());

			this->eventManager->emit(CreatePhysicalBody{ entity });
		}
		else if (light)
		{
			scene->setSceneNode(this->sceneManager->getRootSceneNode()->createChildSceneNode());
			scene->getSceneNode()->attachObject(light->getLight());
		}
	}
}

void GraphicsSystem::setSceneManager(Ogre::SceneManager* sceneManager)
{
	this->sceneManager = sceneManager;
}