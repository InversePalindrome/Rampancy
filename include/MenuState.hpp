/*
Copyright (c) 2017 InversePalindrome
Rampancy - MenuState.hpp
InversePalindrome.com
*/


#pragma once

#include "State.hpp"

#include <MYGUI/MyGUI_Button.h>
#include <MyGUI/MyGUI_Window.h>


class MenuState : public State
{
public:
    virtual void OnExit() override;
    virtual void OnEnter() override;

    virtual hsm::Transition GetTransition() override;

private:
    MyGUI::ButtonPtr newGameButton;
    MyGUI::ButtonPtr loadGameButton;
    MyGUI::ButtonPtr settingsButton;
    MyGUI::ButtonPtr quitButton;

    MyGUI::WindowPtr newGameWindow;
    MyGUI::WindowPtr loadGameWindow;

    void openNewGameTab(MyGUI::WidgetPtr newGameButton);
    void openLoadedGamesTab(MyGUI::WidgetPtr loadGameButton);
    void addGame(MyGUI::WidgetPtr addGameButton);
    void deleteGame(MyGUI::WidgetPtr deleteGameButton);
    void closeWindow(MyGUI::WidgetPtr window, const std::string& button);

    void transitionToGame(MyGUI::WidgetPtr playButton);
    void transitionToSettings(MyGUI::WidgetPtr settingsButton);

    void quitApp(MyGUI::WidgetPtr quitButton);
};