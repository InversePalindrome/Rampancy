/*
Copyright (c) 2017 InversePalindrome
Rampancy - MenuState.cpp
InversePalindrome.com
*/


#include "MenuState.hpp"
#include "GameState.hpp"


void MenuState::OnEnter()
{
	this->playButton = this->getGui()->createWidget<MyGUI::Button>("Button", this->getWindow()->getWidth() / 2 - 125, 
		300, 250, 50, MyGUI::Align::Default, "Main");
	this->playButton->setCaption("Play");
	this->playButton->eventMouseButtonClick += MyGUI::newDelegate(this, &MenuState::transitionToGame);

	this->settingsButton = this->getGui()->createWidget<MyGUI::Button>("Button", this->getWindow()->getWidth() / 2 - 125,
		400, 250, 50, MyGUI::Align::Default, "Main");
	this->settingsButton->setCaption("Settings");
	this->settingsButton->eventMouseButtonClick += MyGUI::newDelegate(this, &MenuState::transitionToSettings);

	this->quitButton = this->getGui()->createWidget<MyGUI::Button>("Button", this->getWindow()->getWidth() / 2 - 125,
		500, 250, 50, MyGUI::Align::Default, "Main");
	this->quitButton->setCaption("Quit");
	this->quitButton->eventMouseButtonClick += MyGUI::newDelegate(this, &MenuState::quitApp);
}

void MenuState::OnExit()
{
	this->getGui()->destroyWidget(this->playButton);
	this->getGui()->destroyWidget(this->settingsButton);
	this->getGui()->destroyWidget(this->quitButton);
}

hsm::Transition MenuState::GetTransition()
{
	if (this->getStateTransition() == StateTransition::Game)
	{
		return hsm::SiblingTransition<GameState>();
	}

	return hsm::NoTransition();
}

void MenuState::transitionToGame(MyGUI::WidgetPtr playButton)
{
	this->setStateTransition(StateTransition::Game);
}

void MenuState::transitionToSettings(MyGUI::WidgetPtr settingsButton)
{
	this->setStateTransition(StateTransition::Settings);
}

void MenuState::quitApp(MyGUI::WidgetPtr quitButton)
{
	this->setShutdown(true);
}