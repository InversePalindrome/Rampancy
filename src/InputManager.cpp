/*
Copyright (c) 2017 InversePalindrome
Rampancy - InputManager.cpp
InversePalindrome.com
*/


#include "InputManager.hpp"

#include <MYGUI/MyGUI_InputManager.h>


void InputManager::initialise(Ogre::RenderWindow* window)
{
	std::size_t windowHandle = 0u;

	window->getCustomAttribute("WINDOW", &windowHandle);
	
	this->inputManager = OIS::InputManager::createInputSystem(windowHandle);
	this->keyboard = static_cast<OIS::Keyboard*>(inputManager->createInputObject(OIS::OISKeyboard, true));
	this->mouse = static_cast<OIS::Mouse*>(inputManager->createInputObject(OIS::OISMouse, true));

	std::size_t width = 0u, height = 0u, depth = 0u;
	std::int32_t left = 0, top = 0;

	window->getMetrics(width, height, depth, left, top);

	const auto& mouseState = this->mouse->getMouseState();
	mouseState.width = width;
	mouseState.height = height;

	this->keyboard->setEventCallback(this);
	this->mouse->setEventCallback(this);
}

InputManager::~InputManager()
{
	this->inputManager->destroyInputObject(this->keyboard);
	this->inputManager->destroyInputObject(this->mouse);
	this->inputManager->destroyInputSystem(this->inputManager);
}

void InputManager::capture()
{
	if (this->keyboard && this->mouse)
	{
		this->keyboard->capture();
		this->mouse->capture();
	}
}

bool InputManager::keyPressed(const OIS::KeyEvent& event)
{
	MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Enum(event.key), event.text);
	
	return true;
}

bool InputManager::keyReleased(const OIS::KeyEvent& event)
{
	MyGUI::InputManager::getInstance().injectKeyRelease(MyGUI::KeyCode::Enum(event.key));

	return true;
}

bool InputManager::mouseMoved(const OIS::MouseEvent& event)
{
	MyGUI::InputManager::getInstance().injectMouseMove(event.state.X.abs, event.state.Y.abs, event.state.Z.abs);

	return true;
}

bool InputManager::mousePressed(const OIS::MouseEvent& event, OIS::MouseButtonID id)
{
    MyGUI::InputManager::getInstance().injectMousePress(event.state.X.abs, event.state.Y.abs, MyGUI::MouseButton::Enum(id));

	return true;
}

bool InputManager::mouseReleased(const OIS::MouseEvent& event, OIS::MouseButtonID id)
{
	MyGUI::InputManager::getInstance().injectMouseRelease(event.state.X.abs, event.state.Y.abs, MyGUI::MouseButton::Enum(id));

	return true;
}

bool InputManager::isKeyPressed(OIS::KeyCode keyCode) const
{
	if (this->keyboard)
	{
		return this->keyboard->isKeyDown(keyCode);
	}

	return false;
}