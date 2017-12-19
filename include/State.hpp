/*
Copyright (c) 2017 InversePalindrome
Rampancy - State.hpp
InversePalindrome.com
*/


#pragma once

#include "Application.hpp"

#include <hsm.h>


class State : public hsm::State
{
public:
	virtual hsm::Transition GetTransition() override;

	Ogre::RenderWindow* getWindow();
	MyGUI::Gui* getGui();
	Ogre::SceneManager* getSceneManager();
	InputManager& getInputManager();

	void setShutdown(bool shutdown);
	void setStateTransition(States stateTransition);
};