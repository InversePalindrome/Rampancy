/*
Copyright (c) 2017 InversePalindrome
Rampancy - MenuState.cpp
InversePalindrome.com
*/


#include "MenuState.hpp"


void MenuState::OnEnter()
{
	this->setChangeState(false);

	auto* entity = this->getSceneManager()->createEntity("Robot", "");
}

void MenuState::OnExit()
{

}