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
	Ogre::SceneManager* getSceneManager();
	InputManager& getInputManager();
	bool getChangeState();

	void setChangeState(bool changeState);
};