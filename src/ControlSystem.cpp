/*
Copyright (c) 2017 InversePalindrome
Rampancy - ControlSystem.cpp
InversePalindrome.com
*/


#include "ControlSystem.hpp"
#include "SceneComponent.hpp"
#include "EntityEvents.hpp"


void ControlSystem::configure(entityx::EventManager& eventManager)
{
	eventManager.subscribe<entityx::ComponentAddedEvent<Player>>(*this);
}

void ControlSystem::update(entityx::EntityManager& entityManager, entityx::EventManager& eventManager, entityx::TimeDelta deltaTime)
{
	this->handleKeyboardInput(eventManager);
	this->handleMouseInput(eventManager);
}

void ControlSystem::receive(const entityx::ComponentAddedEvent<Player>& event)
{
	this->player = event.entity;
}

void ControlSystem::setInputManager(const InputManager* inputManager)
{
	this->inputManager = inputManager;
}

void ControlSystem::handleKeyboardInput(entityx::EventManager& eventManager)
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
		if (this->inputManager->isActive(Action::MoveForward))
		{
			eventManager.emit(ChangeDirection{ this->player, Direction::Forward });
		}
		if (this->inputManager->isActive(Action::MoveBackward))
		{
			eventManager.emit(ChangeDirection{ this->player, Direction::Backward });
		}
	}
}

void ControlSystem::handleMouseInput(entityx::EventManager& eventManager)
{  
	eventManager.emit(ChangeRotation{ this->player, static_cast<float>(this->inputManager->getMouseState().X.abs),
		static_cast<float>(this->inputManager->getMouseState().Y.abs), static_cast<float>(this->inputManager->getMouseState().Z.abs) });
};