/*
Copyright (c) 2017 InversePalindrome
Rampancy - PauseState.cpp
InversePalindrome.com
*/


#include "PauseState.hpp"
#include "MenuState.hpp"


void PauseState::OnEnter()
{
	this->resumeButton = this->getGui()->createWidget<MyGUI::Button>("Button", this->getWindow()->getWidth() / 2 - 125,
		300, 250, 50, MyGUI::Align::Default, "Main");
	this->resumeButton->setCaption("Resume");
	this->resumeButton->eventMouseButtonClick = MyGUI::newDelegate(this, &PauseState::transitionToGame);

	this->settingsButton = this->getGui()->createWidget<MyGUI::Button>("Button", this->getWindow()->getWidth() / 2 - 125,
		400, 250, 50, MyGUI::Align::Default, "Main");
	this->settingsButton->setCaption("Settings");
	this->settingsButton->eventMouseButtonClick = MyGUI::newDelegate(this, &PauseState::transitionToSettings);

	this->quitButton = this->getGui()->createWidget<MyGUI::Button>("Button", this->getWindow()->getWidth() / 2 - 125,
		500, 250, 50, MyGUI::Align::Default, "Main");
	this->quitButton->setCaption("Quit");
	this->quitButton->eventMouseButtonClick = MyGUI::newDelegate(this, &PauseState::transitionToMenu);
}

void PauseState::OnExit()
{
	this->getGui()->destroyWidget(this->resumeButton);
	this->getGui()->destroyWidget(this->settingsButton);
	this->getGui()->destroyWidget(this->quitButton);
}

void PauseState::transitionToGame(MyGUI::WidgetPtr resumeButton)
{
	this->setStateTransition(States::Game);
}

void PauseState::transitionToSettings(MyGUI::WidgetPtr settingsButton)
{
	this->setStateTransition(States::Settings);
}

void PauseState::transitionToMenu(MyGUI::WidgetPtr quitButton)
{
	this->setStateTransition(States::Menu);
}