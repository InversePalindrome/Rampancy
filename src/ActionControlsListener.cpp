/*
Copyright (c) 2017 InversePalindrome
Rampancy - ActionControlsListener.cpp
InversePalindrome.com
*/


#include "ActionControlsListener.hpp"


ActionControlsListener::ActionControlsListener(InputManager* inputManager) :
    inputManager(inputManager),
    currentAction(Action::None)
{
}

void ActionControlsListener::receive(const KeyPressed& event)
{
    this->inputManager->setAction(this->currentAction, event.keyCode);
}