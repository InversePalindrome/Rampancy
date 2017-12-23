/*
Copyright (c) 2017 InversePalindrome
Rampancy - GameState.cpp
InversePalindrome.com
*/


#include "GameState.hpp"
#include "MenuState.hpp"
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

	this->pauseDisplay.initialise(this);
	this->pauseDisplay.setVisible(false);
	
	this->entityParser.parseEntities("entities.xml");
}

void GameState::OnExit()
{
	this->getSceneManager()->clearScene();
}

hsm::Transition GameState::GetTransition()
{
	if (this->getStateTransition() == StateTransition::Menu)
	{
		return hsm::SiblingTransition<MenuState>();
	}

	return hsm::NoTransition();
}

void GameState::Update()
{
	if (this->getInputManager().isKeyPressed(OIS::KC_ESCAPE))
	{	
		this->pauseDisplay.setVisible(true);
	}

    this->systemManager.update_all(0);
}