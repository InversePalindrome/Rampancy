/*
Copyright (c) 2017 InversePalindrome
Rampancy - GameState.cpp
InversePalindrome.com
*/


#include "GameState.hpp"
#include "MenuState.hpp"
#include "PhysicsSystem.hpp"
#include "InputSystem.hpp"


GameState::GameState() :
	entityManager(eventManager),
	systemManager(entityManager, eventManager),
	entityParser(entityManager)
{
	systemManager.add<PhysicsSystem>();
	systemManager.add<InputSystem>();
	
	systemManager.configure();
}

void GameState::OnEnter()
{
	this->systemManager.system<InputSystem>()->setInputManager(&this->getInputManager());

	this->entityParser.setSceneManager(this->getSceneManager());
	this->entityParser.parseEntities("entities.xml");

	this->pauseDisplay.initialise(this);
	this->pauseDisplay.setVisible(false);
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
	if (this->getInputManager().isActive(Action::Quit))
	{	
		this->pauseDisplay.setVisible(true);
	}

    this->systemManager.update_all(0);
}