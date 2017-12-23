/*
Copyright (c) 2017 InversePalindrome
Rampancy - MenuState.hpp
InversePalindrome.com
*/


#pragma once

#include "State.hpp"

#include "MYGUI/MyGUI_Button.h"


class MenuState : public State
{
public:
	virtual void OnExit() override;
	virtual void OnEnter() override;

	virtual hsm::Transition GetTransition() override;

private:
	MyGUI::ButtonPtr playButton;
	MyGUI::ButtonPtr settingsButton;
	MyGUI::ButtonPtr quitButton;

	void transitionToGame(MyGUI::WidgetPtr playButton);
	void transitionToSettings(MyGUI::WidgetPtr settingsButton);
	void quitApp(MyGUI::WidgetPtr quitButton);
};