/*
Copyright (c) 2017 InversePalindrome
Rampancy - PauseState.hpp
InversePalindrome.com
*/


#pragma once

#include "State.hpp"

#include <MYGUI/MyGUI_Button.h>


class PauseState : public State
{
public:
	virtual void OnEnter() override;
	virtual void OnExit() override;

private:
	MyGUI::ButtonPtr resumeButton;
	MyGUI::ButtonPtr settingsButton;
	MyGUI::ButtonPtr quitButton;

	void transitionToGame(MyGUI::WidgetPtr resumeButton);
	void transitionToSettings(MyGUI::WidgetPtr settingsButton);
	void transitionToMenu(MyGUI::WidgetPtr quitButton);
};