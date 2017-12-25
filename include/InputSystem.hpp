/*
Copyright (c) 2017 InversePalindrome
Rampancy - InputSystem.hpp
InversePalindrome.com
*/


#pragma once

#include "InputManager.hpp"
#include "Tags.hpp"

#include <entityx/System.h>


class InputSystem : public entityx::System<InputSystem>, public entityx::Receiver<entityx::ComponentAddedEvent<InputSystem>>
{
public:
	virtual void configure(entityx::EventManager& eventManager) override;
	virtual void update(entityx::EntityManager& entityManager, entityx::EventManager& eventManager, entityx::TimeDelta deltaTime) override;
	virtual void receive(const entityx::ComponentAddedEvent<Player>& event);

	void setInputManager(const InputManager* inputManager);

private:
	const InputManager* inputManager;
	entityx::Entity player;
};