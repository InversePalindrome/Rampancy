/*
Copyright (c) 2017 InversePalindrome
Rampancy - StartState.hpp
InversePalindrome.com
*/


#pragma once

#include "State.hpp"
#include "StartStateListener.hpp"

#include <MYGUI/MyGUI_TextBox.h>

#include <memory>


class StartState : public State
{
public:
    virtual void OnEnter() override;
    virtual void OnExit() override;

    virtual hsm::Transition GetTransition() override;

    virtual void Update() override;

private:
    MyGUI::TextBox* startText;

    std::shared_ptr<StartStateListener> startListener;
};
