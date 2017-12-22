/*
Copyright (c) 2017 InversePalindrome
Rampancy - GameState.cpp
InversePalindrome.com
*/


#include "GameState.hpp"
#include "PauseState.hpp"
#include "PhysicsSystem.hpp"


GameState::GameState() :
	entityManager(eventManager),
	systemManager(entityManager, eventManager),
	entityParser(entityManager)
{
	systemManager.add<PhysicsSystem>();
	
	systemManager.configure();
}

void GameState::OnEnter()
{
	this->entityParser.setSceneManager(this->getSceneManager());
	this->entityParser.parseEntity("Data/Entities/Ogre.xml");
}

void GameState::OnExit()
{
	this->getSceneManager()->clearScene();
}

void GameState::Update()
{
	if (this->getInputManager().isKeyPressed(OIS::KC_ESCAPE))
	{
		this->setStateTransition(States::Pause);
	}

    this->systemManager.update_all(0);
}