/*
Copyright (c) 2017 InversePalindrome
Rampancy - State.cpp
InversePalindrome.com
*/


#include "State.hpp"


Ogre::RenderWindow* State::getWindow()
{
    return reinterpret_cast<Application*>(GetStateMachine().GetOwner())->window;
}

MyGUI::Gui* State::getGui()
{
    return reinterpret_cast<Application*>(GetStateMachine().GetOwner())->gui;
}

Ogre::Camera* State::getCamera()
{
    return reinterpret_cast<Application*>(GetStateMachine().GetOwner())->camera;
}

Ogre::SceneManager* State::getSceneManager()
{
    return reinterpret_cast<Application*>(GetStateMachine().GetOwner())->sceneManager;
}

InputManager& State::getInputManager()
{
    return reinterpret_cast<Application*>(GetStateMachine().GetOwner())->inputManager;
}

EventBus& State::getEventBus()
{
    return reinterpret_cast<Application*>(GetStateMachine().GetOwner())->eventBus;
}

Games& State::getGames()
{
    return reinterpret_cast<Application*>(GetStateMachine().GetOwner())->games;
}

StateTransition State::getStateTransition()
{
    return reinterpret_cast<Application*>(GetStateMachine().GetOwner())->stateTransition;
}

void State::setShutdown(bool shutdown)
{
    reinterpret_cast<Application*>(GetStateMachine().GetOwner())->shutdown = shutdown;
}

void State::setStateTransition(StateTransition stateTransition)
{
    reinterpret_cast<Application*>(GetStateMachine().GetOwner())->stateTransition = stateTransition;
}