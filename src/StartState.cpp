/*
Copyright (c) 2017 InversePalindrome
Rampancy - StartState.cpp
InversePalindrome.com
*/


#include "StartState.hpp"
#include "MenuState.hpp"


void StartState::OnEnter()
{
	this->setChangeState(false);

	this->startText = this->getGui()->createWidget<MyGUI::TextBox>("TextBox", 250, 550, 800, 200, MyGUI::Align::Default, "Main");
	this->startText->setCaption("Press the Spacebar to Continue");
}

void StartState::OnExit()
{
	this->getGui()->destroyWidget(this->startText);
}

hsm::Transition StartState::GetTransition()
{
	if (this->getChangeState())
	{
		return hsm::SiblingTransition<MenuState>();
	}

	return hsm::NoTransition();
}

void StartState::Update()
{
	if (this->getInputManager().isKeyPressed(OIS::KeyCode::KC_SPACE))
	{
		this->setChangeState(true);
	}
}