/*
Copyright (c) 2017 InversePalindrome
Rampancy - SettingsState.cpp
InversePalindrome.com
*/


#pragma once

#include "State.hpp"

#include <MyGUI/MyGUI_Button.h>


class SettingsState : public State
{
public:
	virtual void OnEnter() override;
	virtual void OnExit() override;

	virtual hsm::Transition GetTransition() override;

private:
	MyGUI::ButtonPtr backButton;

    void transitionBack(MyGUI::WidgetPtr backButton);
};