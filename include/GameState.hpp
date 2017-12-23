/*
Copyright (c) 2017 InversePalindrome
Rampancy - GameState.hpp
InversePalindrome.com
*/


#pragma once

#include "State.hpp"
#include "EntityParser.hpp"
#include "PauseDisplay.hpp"

#include <entityx/entityx.h>


class GameState : public State
{
public:
	GameState();

	virtual void OnEnter() override;
	virtual void OnExit() override;

	virtual hsm::Transition GetTransition() override;

	virtual void Update() override;

private:
	entityx::EventManager eventManager;
	entityx::EntityManager entityManager;
	entityx::SystemManager systemManager;

	EntityParser entityParser;

	PauseDisplay pauseDisplay;
};