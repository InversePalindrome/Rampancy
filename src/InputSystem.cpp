/*
Copyright (c) 2017 InversePalindrome
Rampancy - InputSystem.cpp
InversePalindrome.com
*/


#include "InputSystem.hpp"
#include "Events.hpp"


void InputSystem::configure(entityx::EventManager& eventManager)
{
	eventManager.subscribe<entityx::ComponentAddedEvent<Player>>(*this);
}

void InputSystem::update(entityx::EntityManager& entityManager, entityx::EventManager& eventManager, entityx::TimeDelta deltaTime)
{
	if (this->player.valid())
	{
		if (this->inputManager->isActive(Action::MoveLeft))
		{
			eventManager.emit(ChangeDirection{ this->player, Direction::Left });
		}
		if (this->inputManager->isActive(Action::MoveRight))
		{
			eventManager.emit(ChangeDirection{ this->player, Direction::Right });
		}
		if (this->inputManager->isActive(Action::MoveUp))
		{
			eventManager.emit(ChangeDirection{ this->player, Direction::Up });
		}
		if (this->inputManager->isActive(Action::MoveDown))
		{
			eventManager.emit(ChangeDirection{ this->player, Direction::Down });
		}
	}
}

void InputSystem::receive(const entityx::ComponentAddedEvent<Player>& event)
{
	this->player = event.entity;
}

void InputSystem::setInputManager(const InputManager* inputManager)
{
	this->inputManager = inputManager;
}