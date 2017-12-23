/*
Copyright (c) 2017 InversePalindrome
Rampancy - PauseDisplay.cpp
InversePalindrome.com
*/


#include "PauseDisplay.hpp"
#include "GameState.hpp"
#include "MenuState.hpp"
#include "SettingsState.hpp"


PauseDisplay::~PauseDisplay()
{
	this->gameState->getGui()->destroyWidget(this->resumeButton);
    this->gameState->getGui()->destroyWidget(this->quitButton);
}

void PauseDisplay::initialise(GameState* gameState)
{
	this->gameState = gameState;

	this->resumeButton = this->gameState->getGui()->createWidget<MyGUI::Button>("Button", this->gameState->getWindow()->getWidth() / 2 - 125,
		250, 250, 50, MyGUI::Align::Default, "Main");
	this->resumeButton->setCaption("Resume");
	this->resumeButton->eventMouseButtonClick = MyGUI::newDelegate(this, &PauseDisplay::transitionToGame);

	this->quitButton = this->gameState->getGui()->createWidget<MyGUI::Button>("Button", this->gameState->getWindow()->getWidth() / 2 - 125,
		350, 250, 50, MyGUI::Align::Default, "Main");
	this->quitButton->setCaption("Quit");
	this->quitButton->eventMouseButtonClick = MyGUI::newDelegate(this, &PauseDisplay::transitionToMenu);
}

void PauseDisplay::setVisible(bool visibilityStatus)
{
	this->resumeButton->setVisible(visibilityStatus);
	this->quitButton->setVisible(visibilityStatus);
}

void PauseDisplay::transitionToGame(MyGUI::WidgetPtr resumeButton)
{
	this->setVisible(false);
}

void PauseDisplay::transitionToMenu(MyGUI::WidgetPtr quitButton)
{
	this->gameState->setStateTransition(StateTransition::Menu);
}