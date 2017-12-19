/*
Copyright (c) 2017 InversePalindrome
Rampancy - StartState.cpp
InversePalindrome.com
*/


#include "StartState.hpp"
#include "MenuState.hpp"


void StartState::OnEnter()
{
	this->startText = this->getGui()->createWidget<MyGUI::TextBox>("TextBox", 250, 550, 800, 200, MyGUI::Align::Default, "Main");
	this->startText->setCaption("Press the Spacebar to Continue");

	auto* entity = this->getSceneManager()->createEntity("ogrehead.mesh");
}

void StartState::OnExit()
{
	this->getGui()->destroyWidget(this->startText);
}

void StartState::Update()
{
	if (this->getInputManager().isKeyPressed(OIS::KC_SPACE))
	{
		this->setStateTransition(States::Menu);
	}
}