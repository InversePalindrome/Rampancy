/*
Copyright (c) 2017 InversePalindrome
Rampancy - SplashState.hpp
InversePalindrome.com
*/


#pragma once

#include  "State.hpp"
#include "CallbackTimer.hpp"

#include <MYGUI/MyGUI_ImageBox.h>


class SplashState : public State
{
public:
	virtual void OnEnter() override;
	virtual void OnExit() override;

private:
	MyGUI::ImageBox* splashScreen;
	CallbackTimer splashTimer;
};