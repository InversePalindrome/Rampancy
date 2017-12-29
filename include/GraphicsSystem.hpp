/*
Copyright (c) 2017 InversePalindrome
Rampancy - GraphicsSystem.hpp
InversePalindrome.com
*/


#pragma once

#include "SceneComponent.hpp"
#include "Events.hpp"

#include <OGRE/OgreSceneManager.h>

#include <entityx/System.h>


class GraphicsSystem : public entityx::System<GraphicsSystem>, public entityx::Receiver<GraphicsSystem>
{
public:
	virtual void configure(entityx::EventManager& eventManager) override;
	virtual void update(entityx::EntityManager& entityManager, entityx::EventManager& eventManager, entityx::TimeDelta deltaTime) override;

	virtual void receive(const EntityParsed& event);

	void setSceneManager(Ogre::SceneManager* sceneManager);

private:
	Ogre::SceneManager* sceneManager;
	entityx::EventManager* eventManager;
};