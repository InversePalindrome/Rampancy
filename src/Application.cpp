/*
Copyright (c) 2017 InversePalindrome
Rampancy - Application.cpp
InversePalindrome.com
*/


#include "Application.hpp"
#include "SplashState.hpp"

#include <OGRE/OgreConfigFile.h>
#include <OGRE/OgreResourceGroupManager.h>


Application::Application() :
	root(new Ogre::Root()),
	window(nullptr),
	sceneManager(root->createSceneManager(Ogre::ST_GENERIC)),
	camera(nullptr),
	gui(new MyGUI::Gui()),
	guiPlatform(new MyGUI::OgrePlatform()),
    stateTransition(StateTransition::None),
	shutdown(false)
{
	if (root->showConfigDialog())
	{
		window = root->initialise(true, "Rampancy");
	}

	loadResources();

	setupCamera();
	
	root->addFrameListener(this);

	inputManager.initialise(window);
	
	Ogre::WindowEventUtilities::addWindowEventListener(window, this);

	guiPlatform->initialise(window, sceneManager);
	gui->initialise();

	stateMachine.Initialize<SplashState>(this);
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
		this->handleEvent();
		this->update();
		this->render();
	}
}

void Application::handleEvent()
{
	Ogre::WindowEventUtilities::messagePump();
	
	this->inputManager.capture();
}

void Application::update()
{
	this->stateMachine.ProcessStateTransitions();
	this->stateMachine.UpdateStates();
}

void Application::render()
{
	this->root->renderOneFrame();
}

void Application::loadResources()
{
	Ogre::ConfigFile cf;
	
	Ogre::String resourceFile;

    #ifdef _DEBUG
	resourceFile = "resources_d.cfg";
    #else
	resourceFile = "resources.cfg";
    #endif 

	cf.load(resourceFile);

	auto seci = cf.getSectionIterator();

	while (seci.hasMoreElements())
	{
		const auto& secName = seci.peekNextKey();

		const auto* settings = seci.getNext();
	
		for (const auto& setting : *settings)
		{
			const auto& typeName = setting.first;
			const auto& archName = setting.second;

			Ogre::ResourceGroupManager::getSingleton().addResourceLocation(archName, typeName, secName);
		}
	}

	Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();
}

void Application::setupCamera()
{
	this->camera = this->sceneManager->createCamera("Main");
	this->camera->setPosition({ 0, 0, 0 });
	this->camera->setNearClipDistance(5);

	auto* viewport = this->window->addViewport(camera);
	viewport->setBackgroundColour(Ogre::ColourValue(255.f, 255.f, 255.f));

	this->camera->setAspectRatio(Ogre::Real(viewport->getActualWidth()) / Ogre::Real(viewport->getActualHeight()));
}