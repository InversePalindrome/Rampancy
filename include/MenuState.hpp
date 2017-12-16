/*
Copyright (c) 2017 InversePalindrome
Rampancy - MenuState.hpp
InversePalindrome.com
*/


#pragma once

#include "State.hpp"


class MenuState : public State
{
public:
	virtual void OnExit() override;
	virtual void OnEnter() override;
};