/*
Copyright (c) 2017 InversePalindrome
Rampancy - SettingsState.cpp
InversePalindrome.com
*/


#pragma once

#include "Events.hpp"
#include "InputManager.hpp"


struct ActionControlsListener
{
	ActionControlsListener(InputManager* inputManager);

	void receive(const KeyPressed& event);

	InputManager* inputManager;
	Action currentAction;
};
