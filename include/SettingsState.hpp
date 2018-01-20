/*
Copyright (c) 2017 InversePalindrome
Rampancy - SettingsState.cpp
InversePalindrome.com
*/


#pragma once

#include "State.hpp"
#include "Events.hpp"
#include "ActionControlsListener.hpp"

#include <MyGUI/MyGUI_Button.h>

#include <vector>
#include <memory>


class SettingsState : public State
{
public:
	virtual void OnEnter() override;
	virtual void OnExit() override;

	virtual hsm::Transition GetTransition() override;

private:
	MyGUI::ButtonPtr backButton;
	std::vector<MyGUI::ButtonPtr> actionButtons;

	std::shared_ptr<ActionControlsListener> actionControls;

	void enableChangingControls(MyGUI::WidgetPtr newButton, MyGUI::WidgetPtr oldButton);
	void disableChangingControls(MyGUI::WidgetPtr sender, MyGUI::WidgetPtr newFocus);
	void closeWindow(MyGUI::WidgetPtr window, const std::string& button);
    void transitionBack(MyGUI::WidgetPtr backButton);
};