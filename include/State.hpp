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
	Ogre::RenderWindow* getWindow();
	MyGUI::Gui* getGui();
	Ogre::Camera* getCamera();
	Ogre::SceneManager* getSceneManager();
	InputManager& getInputManager();
	StateTransition getStateTransition();
	Games& getGames();

	void setShutdown(bool shutdown);
	void setStateTransition(StateTransition stateTransition);
};