/*
Copyright (c) 2017 InversePalindrome
Rampancy - State.cpp
InversePalindrome.com
*/


#include "State.hpp"
#include "States.hpp"
#include "SplashState.hpp"
#include "StartState.hpp"
#include "MenuState.hpp"
#include "GameState.hpp"
#include "SettingsState.hpp"
#include "PauseState.hpp"


hsm::Transition State::GetTransition()
{
	auto* app = reinterpret_cast<Application*>(GetStateMachine().GetOwner());

	auto currentTransition = app->stateTransition;
	app->stateTransition = States::None;

	switch (currentTransition)
	{
	case States::Splash:
		return hsm::SiblingTransition<SplashState>();
	case States::Start:
		return hsm::SiblingTransition<StartState>();
	case States::Menu:
		return hsm::SiblingTransition<MenuState>();
	case States::Game:
		return hsm::SiblingTransition<GameState>();
	case States::Settings:
		return hsm::SiblingTransition<SettingsState>();
	case States::Pause:
		return hsm::SiblingTransition<PauseState>();
	}

	return hsm::NoTransition();
}

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

void State::setShutdown(bool shutdown)
{
	reinterpret_cast<Application*>(GetStateMachine().GetOwner())->shutdown = shutdown;
}

void State::setStateTransition(States stateTransition)
{
	reinterpret_cast<Application*>(GetStateMachine().GetOwner())->stateTransition = stateTransition;
}