/*
Copyright (c) 2017 InversePalindrome
Rampancy - State.cpp
InversePalindrome.com
*/


#include "State.hpp"


Ogre::RenderWindow* State::getWindow()
{
	return reinterpret_cast<Application*>(this->GetStateMachine().GetOwner())->window;
}

MyGUI::Gui* State::getGui()
{
	return reinterpret_cast<Application*>(this->GetStateMachine().GetOwner())->gui;
}

Ogre::SceneManager* State::getSceneManager()
{
	return reinterpret_cast<Application*>(this->GetStateMachine().GetOwner())->sceneManager;
}

InputManager& State::getInputManager()
{
	return reinterpret_cast<Application*>(this->GetStateMachine().GetOwner())->inputManager;
}

bool State::getChangeState()
{
	return reinterpret_cast<Application*>(this->GetStateMachine().GetOwner())->changeState;
}

void State::setChangeState(bool changeState)
{
	reinterpret_cast<Application*>(this->GetStateMachine().GetOwner())->changeState = changeState;
}