/*
Copyright (c) 2017 InversePalindrome
Rampancy - Application.cpp
InversePalindrome.com
*/


#include "Application.hpp"


Application::Application() :
	root(new Ogre::Root()),
	window(nullptr),
	sceneManager(root->createSceneManager(Ogre::ST_GENERIC)),
	camera(nullptr),
	gui(new MyGUI::Gui()),
	guiPlatform(new MyGUI::OgrePlatform()),
	shutdown(false)
{
	window = root->initialise(true, "Rampancy");
	
	root->addFrameListener(this);

	camera = sceneManager->createCamera("Main");

	inputManager.initialise(window);

	Ogre::WindowEventUtilities::addWindowEventListener(window, this);

	gui->initialise();
	guiPlatform->initialise(window, sceneManager);
}

Application::~Application()
{
	this->gui->shutdown();
	this->guiPlatform->shutdown();

	Ogre::WindowEventUtilities::removeWindowEventListener(this->window, this);

	delete this->gui;
	delete this->guiPlatform;
	delete this->root;
}

void Application::run()
{
	while (!this->shutdown)
	{
		this->inputManager.capture();

		this->handleEvents();

		Ogre::WindowEventUtilities::messagePump();

		this->root->renderOneFrame();
	}
}

void Application::handleEvents()
{
	if (this->inputManager.isKeyPressed(OIS::KC_ESCAPE))
	{
		this->shutdown = true;
	}
}