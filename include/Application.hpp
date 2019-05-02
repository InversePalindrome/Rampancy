/*
Copyright (c) 2017 InversePalindrome
Rampancy - Application.hpp
InversePalindrome.com
*/


#pragma once

#include "Games.hpp"
#include "Events.hpp"
#include "InputManager.hpp"
#include "StateTransitions.hpp"

#include <hsm.h>

#include <MYGUI/MyGUI.h>
#include <MYGUI/MyGUI_OgrePlatform.h>

#include <OGRE/OgreRoot.h>
#include <OGRE/OgreRenderWindow.h>
#include <OGRE/OgreSceneManager.h>
#include <OGRE/OgreCamera.h>
#include <OGRE/OgreFrameListener.h>
#include <OGRE/OgreWindowEventUtilities.h>

#include <vector>


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

    EventBus eventBus;
    InputManager inputManager;

    hsm::StateMachine stateMachine;
    StateTransition stateTransition;

    Games games;

    bool shutdown;
    bool isConfigured;

    void handleEvent();
    void update();
    void render();

    bool configure();
    void initialise();
    void loadResources();
    void addCamera();
};