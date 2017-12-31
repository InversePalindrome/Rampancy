/*
Copyright (c) 2017 InversePalindrome
Rampancy - SettingsState.cpp
InversePalindrome.com
*/


#include "SettingsState.hpp"
#include "MenuState.hpp"


void SettingsState::OnEnter()
{
	this->backButton = this->getGui()->createWidget<MyGUI::Button>("Button", 0, 0, 150, 50, MyGUI::Align::Default, "Main");

	this->backButton->setCaption("Back");

	this->backButton->eventMouseButtonClick = MyGUI::newDelegate(this, &SettingsState::transitionBack);
}

void SettingsState::OnExit()
{
	this->getGui()->destroyWidget(this->backButton);
}

hsm::Transition SettingsState::GetTransition()
{
	if (this->getStateTransition() == StateTransition::Menu)
	{
		return hsm::SiblingTransition<MenuState>();
	}

	return hsm::NoTransition();
}

void SettingsState::transitionBack(MyGUI::WidgetPtr backButton)
{
	this->setStateTransition(StateTransition::Menu);
}