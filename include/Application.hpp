/*
Copyright (c) 2017 InversePalindrome
Rampancy - Application.hpp
InversePalindrome.com
*/


#pragma once

#include "InputManager.hpp"

#include <MYGUI/MyGUI.h>
#include <MYGUI/MyGUI_OgrePlatform.h>

#include <OGRE/OgreRoot.h>
#include <OGRE/OgreRenderWindow.h>
#include <OGRE/OgreSceneManager.h>
#include <OGRE/OgreCamera.h>
#include <OGRE/OgreFrameListener.h>
#include <OGRE/OgreWindowEventUtilities.h>

#include <hsm.h>


class State;

class Application : public Ogre::FrameListener, public Ogre::WindowEventListener
{
	friend class State;

public:
	Application();
	Application(const Application&) = delete;
	Application& operator=(const Application&) = delete;

	~Application();

	void run();

private:
	Ogre::Root* root;
	Ogre::RenderWindow* window;
	Ogre::SceneManager* sceneManager;
	Ogre::Camera* camera;

	MyGUI::Gui* gui;
	MyGUI::OgrePlatform* guiPlatform;

	InputManager inputManager;

	hsm::StateMachine stateMachine;

	bool changeState;
	bool shutdown;

	void handleEvent();
	void update();
	void render();

	void loadResources();
	void setupCamera();
};