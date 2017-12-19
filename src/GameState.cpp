/*
Copyright (c) 2017 InversePalindrome
Rampancy - GameState.cpp
InversePalindrome.com
*/


#include "GameState.hpp"
#include "PauseState.hpp"


GameState::GameState() :
	entityManager(eventManager),
	systemManager(entityManager, eventManager)
{
	systemManager.configure();
}

void GameState::OnEnter()
{

}

void GameState::OnExit()
{
	
}

void GameState::Update()
{
	if (this->getInputManager().isKeyPressed(OIS::KC_ESCAPE))
	{
		this->setStateTransition(States::Pause);
	}

    this->systemManager.update_all(0);
}