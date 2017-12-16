/*
Copyright (c) 2017 InversePalindrome
Rampancy - SplashState.cpp
InversePalindrome.com
*/


#include "SplashState.hpp"
#include "StartState.hpp"
 

void SplashState::OnEnter()
{
	this->splashScreen = this->getGui()->createWidget<MyGUI::ImageBox>("ImageBox", this->getWindow()->getWidth() / 2 - 256, this->getWindow()->getHeight() / 2 - 128,
		512, 256, MyGUI::Align::Default, "Main");

	this->splashScreen->setImageTexture("InversePalindromeLogo.png");

	const auto splashTime = 2500u;
	
	this->splashTimer.addCallback([this](const auto& error)
	{
		this->setChangeState(true);
	}
	, splashTime);
}

void SplashState::OnExit()
{
	this->getGui()->destroyWidget(this->splashScreen);
}

hsm::Transition SplashState::GetTransition()
{
	if (this->getChangeState())
	{
		return hsm::SiblingTransition<StartState>();
	}

	return hsm::NoTransition();
}