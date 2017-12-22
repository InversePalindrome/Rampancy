/*
Copyright (c) 2017 InversePalindrome
Rampancy - StartState.cpp
InversePalindrome.com
*/


#include "StartState.hpp"
#include "MenuState.hpp"


void StartState::OnEnter()
{
	this->startText = this->getGui()->createWidget<MyGUI::TextBox>("TextBox", 250, 550, 800, 200, MyGUI::Align::Default, "Main");
	this->startText->setCaption("Press the Spacebar to Continue");

	auto* entity = this->getSceneManager()->createEntity("ogre.mesh");
	
	auto* node = this->getSceneManager()->getRootSceneNode()->createChildSceneNode("Ogre");
	node->setPosition(0, 0, 0);
	node->attachObject(entity);
	
	auto* light = this->getSceneManager()->createLight();
	light->setType(Ogre::Light::LT_SPOTLIGHT);
	light->setDirection(Ogre::Vector3::NEGATIVE_UNIT_Z);

	auto* lightNode = this->getSceneManager()->getRootSceneNode()->createChildSceneNode();
	lightNode->attachObject(light);
	lightNode->setDirection(0, 0, -1);
	lightNode->setPosition({ 0, 0, 200 });
}

void StartState::OnExit()
{
	this->getGui()->destroyWidget(this->startText);
	this->getSceneManager()->clearScene();
}

void StartState::Update()
{
	if (this->getInputManager().isKeyPressed(OIS::KC_SPACE))
	{
		this->setStateTransition(States::Menu);
	}

	this->getSceneManager()->getSceneNode("Ogre")->rotate(Ogre::Vector3::UNIT_Y, Ogre::Degree(0.1f));
}